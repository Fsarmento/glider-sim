
const uint8_t SWITCH_PINS[] = {
  0, // 0 - Joystick Button 0
  5, // 1 - Joystick Button 1
  6, // 2 - Joystick Button 2
  7, // 3 - Joystick Button 3
  10, // 4 - Joystick Button 4
  20, // 5 - Joystick Button 5
};

const uint8_t ALT_PINS[] = {
  4, // Joystick Alt UP - 0
  1, // Joystick Alt Right - 90
  2, // Joystick Alt Down - 180
  3, // Joystick Alt Left - 270
};


boolean lastButtonState[sizeof(SWITCH_PINS)];
int8_t lastAltState = -1;
boolean isAltPressed = 0;
boolean led_on = 0;

void setup() {
  // Setup digital switches
  for (size_t i = 0; i < sizeof(SWITCH_PINS); i++) {
    pinMode(SWITCH_PINS[i], INPUT_PULLUP);
  }

  // Setup alt switches
  for (size_t i = 0; i < sizeof(ALT_PINS); i++) {
    pinMode(ALT_PINS[i], INPUT_PULLUP);
  }

  // Internal LED pin
  pinMode(8, OUTPUT);

  // Start comunication
  Serial1.begin(115200, SERIAL_8N1, -1, 21);
  //Serial.begin(115200);

}

void loop() {
  led_on = 0;
   // Read Switches
  for (size_t i = 0; i < sizeof(SWITCH_PINS); i++) {
    int currentButtonState = !digitalRead(SWITCH_PINS[i]);
    if (currentButtonState != lastButtonState[i]) {
      sendPos(i, currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
    if (currentButtonState) {
      led_on = 1;
    }
  }


  // Real Alt Switche
  isAltPressed = 0;
  for (size_t i = 0; i < sizeof(ALT_PINS); i++) {
    boolean isPressed = !digitalRead(ALT_PINS[i]);
    isAltPressed = isAltPressed || isPressed;
    if (isPressed && lastAltState != i ) {
      // a new direction is pressed
      sendPos(20, i * 90);
      lastAltState = i;
      break;
    }
  }
  if (!isAltPressed && lastAltState != -1 ) {
      // no direction is pressed
      sendPos(20, -1);
      lastAltState = -1;
  }
  led_on = led_on || isAltPressed;

  if (led_on == 1) {
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
  }
} 

void sendPos(uint8_t id, int state)  {
  Serial1.print('<');
  Serial1.print(id);
  Serial1.print(":");
  Serial1.print(state);
  Serial1.print('>');

  //Serial.print(id);
  //Serial.print(":");
  //Serial.println(state);
  delay(100);
}
