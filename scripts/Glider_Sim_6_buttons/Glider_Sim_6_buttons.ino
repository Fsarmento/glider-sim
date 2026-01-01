const int BTN_1_PIN = 0;   // 1/7
const int BTN_2_PIN = 1;   // 2/7
const int BTN_3_PIN = 6;   // 3/7
const int BTN_4_PIN = 20;  // 4/7
const int BTN_5_PIN = 10;  // 5/7
const int BTN_6_PIN = 5;   // 6/7

const int PWM_PIN   = 21;
const int LED_PIN   = 8;


void setup() {
  // Setup digital switches
  pinMode(BTN_1_PIN, INPUT_PULLUP);
  pinMode(BTN_2_PIN, INPUT_PULLUP);
  pinMode(BTN_3_PIN, INPUT_PULLUP);
  pinMode(BTN_4_PIN, INPUT_PULLUP);
  pinMode(BTN_5_PIN, INPUT_PULLUP);
  pinMode(BTN_6_PIN, INPUT_PULLUP);

  // Internal LED pin
  pinMode(LED_PIN, OUTPUT);

  pinMode(PWM_PIN, OUTPUT);
  analogWrite(PWM_PIN, 0);   // começa a 0% (nenhum botão)

  // Start comunication for debug
  // Serial.begin(115200);

}

void loop() {
  int dutyIndex = 1; // 1 = idle

if (digitalRead(BTN_1_PIN) == LOW)      dutyIndex = 2;
else if (digitalRead(BTN_2_PIN) == LOW) dutyIndex = 3;
else if (digitalRead(BTN_3_PIN) == LOW) dutyIndex = 4;
else if (digitalRead(BTN_4_PIN) == LOW) dutyIndex = 5;
else if (digitalRead(BTN_5_PIN) == LOW) dutyIndex = 6;
else if (digitalRead(BTN_6_PIN) == LOW) dutyIndex = 7;
// senão fica 1 (idle)

  // analogWrite no ESP32 aceita 0..255 por omissão (8 bits)
  const int MAX_DUTY = 250;
  const int STEPS = 7;
  int duty = (MAX_DUTY * dutyIndex) / STEPS;  // 1..7

  analogWrite(PWM_PIN, duty);

  // liga o led se um botão estiver pressionado
  if (dutyIndex > 1) {
    digitalWrite(LED_PIN, LOW);
  } else {
    digitalWrite(LED_PIN, HIGH);
  }

  // Serial.print("dutyIndex: ");
  // Serial.print(dutyIndex);
  // Serial.print("    duty: ");
  // Serial.println(duty);

  delay(100);
} 




