// Requires Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_JOYSTICK);  //, 32, 1,
//true, true, true, false, false, false,
//true, false, false, true, false);
// false, false, false, false, false);

// RX no pino 14 (Aux 4), TX em -1 (desabilitado)

int bitResolution = 12;
long sampleValue = 0;
int numberOfSamples = 1;
int sampleMaxValue = 1 << bitResolution;

// Tolerância em duty-cycle para detetar níveis (±5%)
const float DUTY_TOL = 0.05;

// 6-buttons
// Níveis ideais (0, 1/6, 2/6, 3/6, 4/6, 5/6, 6/6)    (MAX_DUTY * dutyIndex) / STEPS;
  const int MAX_DUTY = 250;
  const int STEPS = 7;
const float dutyLevels[7] = {
  (MAX_DUTY * 1.0) / (STEPS * 255.0),        // 0 = nenhum botão
  (MAX_DUTY * 2.0) / (STEPS * 255.0),  // 1 = botão 1 (GPIO 0 no ESP32)
  (MAX_DUTY * 3.0) / (STEPS * 255.0),  // 2 = botão 2 (GPIO 1)
  (MAX_DUTY * 4.0) / (STEPS * 255.0),  // 3 = botão 3 (GPIO 6)
  (MAX_DUTY * 5.0) / (STEPS * 255.0),  // 4 = botão 4 (GPIO 20)
  (MAX_DUTY * 6.0) / (STEPS * 255.0),  // 5 = botão 5 (GPIO 10)
  (MAX_DUTY * 7.0) / (STEPS * 255.0)   // 6 = botão 6 (GPIO 5) → duty ≈ 100% (250)
};


const uint8_t LINEAR_PINS[] = {
  A6,  // JoystickX, Hall effect
  A7,  // JoystickY, Hall effect
  A8,  // Slider (Rudder?)
  A9,  // Slider (Air-break?)
  A3,  // Slider (Flaps?)
  A2,  // Slider (Trim?)
  A1,  // Slider (wheel up/down - D)
};

// buttons 0 to 5 (6 buttons) read from Serial port 1 - Stick
// buttons 6 and 7 read from Aux 1 and Aux 4 ports
int INIT_INT_PIN = 6;
// buttons 8 to 13 (6 buttons) read from Serial port Aux 2 - Menu 6-Buttons 1
int INIT_MB1_PIN = 8;
// buttons 14 to 19 (6 buttons) read from Serial port Aux 3 - Menu 6-Buttons 2
int INIT_MB2_PIN = 14;



const uint8_t SWITCH_PINS[] = {
  18,  // Aux 1 - switch
  14,  // Aux 4   switch
};


const uint8_t BUTTONS6_PINS[] = {

  10,  // Aux 2 - 6 botões
  16,  // Aux 3 - 6 botões
};

boolean lastSwitchState[sizeof(SWITCH_PINS)];


// estado atual dos dois keypads 6-botoes
int current6ButtonValue[sizeof(BUTTONS6_PINS)] = { 0 };
unsigned long lastPwmReadMillis = 0;
const unsigned long PWM_READ_INTERVAL = 20;  // ms entre leituras

void setup() {
  // Setup analog inputs
  for (size_t i = 0; i < sizeof(LINEAR_PINS); i++) {
    pinMode(LINEAR_PINS[i], INPUT_PULLUP);
  }
  // Setup digital switches
  for (size_t i = 0; i < sizeof(SWITCH_PINS); i++) {
    pinMode(SWITCH_PINS[i], INPUT_PULLUP);
  }

  // Setup PWM pins 6 button pins
  for (size_t i = 0; i < sizeof(BUTTONS6_PINS); i++) {
    pinMode(BUTTONS6_PINS[i], INPUT);
  }

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, sampleMaxValue);
  Joystick.setYAxisRange(0, sampleMaxValue);
  Joystick.setZAxisRange(0, sampleMaxValue);
  Joystick.setRxAxisRange(0, sampleMaxValue);
  Joystick.setRyAxisRange(0, sampleMaxValue);
  Joystick.setRzAxisRange(0, sampleMaxValue);
  Joystick.setThrottleRange(0, sampleMaxValue);

  // Calculate number of samples
  numberOfSamples = (bitResolution - 10) < 1 ? 1 : 1 << ((bitResolution - 10) << 1);

  // Start comunication for debuging
  // Serial.begin(115200);
  // Start comunication with stick and menu buttons
  Serial1.begin(115200);
}

void loop() {

  // Read Switches from Serial - Stick
  while (Serial1.available() > 0) {
    char c = Serial1.read();

    if (c == '<') {
      uint8_t button = Serial1.parseInt();
      int state = Serial1.parseInt();

      if (button >= 20) {
        Joystick.setHatSwitch(button - 20, state);
      } else if (button >= 0 && button <= 5) {  // Stick configurável até 6 botoes
        Joystick.setButton(button, state);
      }
    }
  }


  // Read Switches from board
  for (size_t i = 0; i < sizeof(SWITCH_PINS); i++) {
    int currentButtonState = !digitalRead(SWITCH_PINS[i]);
    if (currentButtonState != lastSwitchState[i]) {
      Joystick.setButton(i + INIT_INT_PIN, currentButtonState);
      lastSwitchState[i] = currentButtonState;
    }
  }


  // Read Switches from 6-buttons keypad
  // Atualiza leitura dos keypads 6-botoes a cada PWM_READ_INTERVAL ms
  unsigned long now = millis();
  if (now - lastPwmReadMillis >= PWM_READ_INTERVAL) {
    lastPwmReadMillis = now;

    for (size_t i = 0; i < sizeof(BUTTONS6_PINS); i++) {
      int level = buttonPressed(BUTTONS6_PINS[i]);  // 0..6 ou -1

      if (level >= 0 && level != current6ButtonValue[i]) {
        current6ButtonValue[i] = level;

        // Exemplo de mapeamento: 6 níveis → 6 botões Joystick
        // Escolhe um offset adequado para este keypad
        int baseButtonIndex = (i == 0) ? INIT_MB1_PIN : INIT_MB2_PIN;

        // Primeiro limpa os 6 botões desse grupo
        for (int b = 0; b < 6; b++) {
          Joystick.setButton(baseButtonIndex + b, 0);
        }
        if (level > 0 && level <= 6) {
          Joystick.setButton(baseButtonIndex + (level - 1), 1);
        }
      }
    }
  }



  // Output Controls
  // Joystick.setXAxis(sampleMaxValue - overSample(LINEAR_PINS[0]));  // inverte sinal no eixo x
  Joystick.setXAxis(overSample(LINEAR_PINS[0]));
  Joystick.setYAxis(overSample(LINEAR_PINS[1]));
  Joystick.setZAxis(overSample(LINEAR_PINS[2]));
  Joystick.setRxAxis(overSample(LINEAR_PINS[3]));
  Joystick.setRyAxis(overSample(LINEAR_PINS[4]));
  Joystick.setRzAxis(overSample(LINEAR_PINS[5]));
  Joystick.setThrottle(overSample(LINEAR_PINS[6]));

  Joystick.sendState();
}

int overSample(int analogPin) {
  sampleValue = analogRead(analogPin);
  for (int n = 1; n < numberOfSamples; n++) {
    sampleValue += analogRead(analogPin);
  }
  return ((int)((sampleValue >> (bitResolution - 10)) + (1 << bitResolution - 11) - 1));
}





int buttonPressed(int PWM_IN_PIN) {
  const unsigned long TIMEOUT_US = 5000;  // 5 ms

  unsigned long highTime = pulseIn(PWM_IN_PIN, HIGH, TIMEOUT_US);
  unsigned long lowTime = pulseIn(PWM_IN_PIN, LOW, TIMEOUT_US);

  // Se não mediu ciclo completo, devolve -1 (sem alteração)
  if (highTime == 0 || lowTime == 0) {
    return -1;
  }

  unsigned long period = highTime + lowTime;
  float duty = (float)highTime / (float)period;

  int detectedLevel = -1;
  float bestDiff = 1.0;

  for (int i = 0; i < 7; i++) {
    float diff = fabs(duty - dutyLevels[i]);
    if (diff < bestDiff) {
      bestDiff = diff;
      detectedLevel = i;
    }
  }

  if (detectedLevel >= 0 && bestDiff <= DUTY_TOL) {
    return detectedLevel;  // 0..6
  } else {
    return -1;  // sem nível válido
  }
}
