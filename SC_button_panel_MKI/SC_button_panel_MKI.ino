#include <Keyboard.h>
bool lastStateAtc = HIGH;
bool lastStateAcc = HIGH;
bool lastStateDecl = HIGH;
bool lastStatePwr = LOW;
bool lastStateShld = HIGH;
bool lastStateThrst = HIGH;
bool lastStateWep = HIGH;
bool lastStateGear = HIGH;
bool lastStateVtol = HIGH;
bool lastStateGmbl1 = HIGH;
bool lastStateGmbl2 = HIGH;
bool lastStateFire = HIGH;
bool lastStateDoor = HIGH;
bool lastStateLock = HIGH;
byte gimbalState = 1;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);


  //Checking the flip switch state to prevent rogue keypressen when the logic starts.
  lastStatePwr = digitalRead(2);
  lastStateShld = digitalRead(3);
  lastStateThrst = digitalRead(4);
  lastStateWep = digitalRead(5);
  lastStateGear = digitalRead(6);
  lastStateVtol = digitalRead(7);
  lastStateGmbl1 = digitalRead(8);
  lastStateGmbl2 = digitalRead(9);
  lastStateFire = digitalRead(10);
  lastStateDoor = digitalRead(14);
  lastStateLock = digitalRead(15);


  Keyboard.begin(KeyboardLayout_de_DE);
  //Serial.begin(115200);
}

void loop() {
  //ATC
  int buttonStateAtc = digitalRead(15);
  if ((buttonStateAtc != lastStateAtc) && (buttonStateAtc == LOW)) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press('n');
    delay(10);
    Keyboard.releaseAll();
    delay(200);
  }
  lastStateAtc = buttonStateAtc;

  //Accept
  int buttonStateAcc = digitalRead(18);
  if ((buttonStateAcc != lastStateAcc) && (buttonStateAcc == LOW)) {
    Keyboard.press((136 + 0x2f));
    delay(10);
    Keyboard.releaseAll();
    delay(200);
  }
  lastStateAcc = buttonStateAcc;

  //Decline
  int buttonStateDecl = digitalRead(19);
  if ((buttonStateDecl != lastStateDecl) && (buttonStateDecl == LOW)) {
    Keyboard.press('+');
    delay(10);
    Keyboard.releaseAll();
    delay(200);
  }
  lastStateDecl = buttonStateDecl;

  //Power
  if (digitalRead(2) != lastStatePwr) {
    Keyboard.press('u');
    delay(10);
    Keyboard.releaseAll();
    lastStatePwr = !lastStatePwr;
  }

  //Shields
  if (digitalRead(3) != lastStateShld) {
    Keyboard.press('o');
    delay(10);
    Keyboard.releaseAll();
    lastStateShld = !lastStateShld;
  }

  //Thrusters
  if (digitalRead(4) != lastStateThrst) {
    Keyboard.press('i');
    delay(10);
    Keyboard.releaseAll();
    lastStateThrst = !lastStateThrst;
  }

  //Weapons
  if (digitalRead(5) != lastStateWep) {
    Keyboard.press('p');
    delay(10);
    Keyboard.releaseAll();
    lastStateWep = !lastStateWep;
  }

  //Landing gear
  if (digitalRead(6) != lastStateGear) {
    Keyboard.press('n');
    delay(10);
    Keyboard.releaseAll();
    lastStateGear = !lastStateGear;
  }

  //VTOL
  if (digitalRead(7) != lastStateVtol) {
    Keyboard.press('k');
    delay(10);
    Keyboard.releaseAll();
    lastStateVtol = !lastStateVtol;
  }

//  //Gimbal mode 1
//  if (digitalRead(8) != lastStateGmbl1) {
//    Keyboard.press('g');
//    delay(10);
//    Keyboard.releaseAll();
//    lastStateGmbl1 = !lastStateGmbl1;
//  }
//
//  //Gimbal mode 2
//  if (digitalRead(9) != lastStateGmbl2) {
//    Keyboard.press('g');
//    delay(10);
//    Keyboard.releaseAll();
//    lastStateGmbl2 = !lastStateGmbl2;
//  }

  //Gimbal mode pro
  if (digitalRead (8) == LOW && digitalRead(9) == HIGH && gimbalState == 2) {
    Keyboard.press('g');
    delay(10);
    Keyboard.releaseAll();
    gimbalState = 1;
  }
  else if (digitalRead (8) == LOW && digitalRead(9) == HIGH && gimbalState == 3) {
    Keyboard.write('g');
    delay(10);
    Keyboard.write('g');
    delay(10);
    gimbalState = 1;
  }
  else if (digitalRead (8) == HIGH && digitalRead(9) == HIGH && gimbalState == 1) {
    Keyboard.write('g');
    delay(10);
    Keyboard.write('g');
    delay(10);
    gimbalState = 2;
  }
  else if (digitalRead (8) == HIGH && digitalRead(9) == HIGH && gimbalState == 3) {
    Keyboard.write('g');
    delay(10);
    gimbalState = 2;
  }
  else if (digitalRead (8) == HIGH && digitalRead(9) == LOW && gimbalState == 1) {
    Keyboard.write('g');
    delay(10);
    gimbalState = 3;
  }
  else if (digitalRead (8) == HIGH && digitalRead(9) == LOW && gimbalState == 2) {
    Keyboard.write('g');
    delay(10);
    Keyboard.write('g');
    delay(10);
    gimbalState = 3;
  }

  //Fire mode
  if (digitalRead(10) != lastStateFire) {
    Keyboard.press(KEY_RIGHT_ALT);
    delay(10);
    Keyboard.press(KEY_INSERT);
    delay(10);
    Keyboard.releaseAll();
    lastStateFire = !lastStateFire;
  }

  //Doors open
  if (digitalRead(16) != lastStateDoor && digitalRead(16) == LOW) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press('o');
    delay(10);
    Keyboard.releaseAll();
    lastStateDoor = !lastStateDoor;
  }

  //Doors close
  if (digitalRead(16) != lastStateDoor && digitalRead(16) == HIGH) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press('k');
    delay(10);
    Keyboard.releaseAll();
    lastStateDoor = !lastStateDoor;
  }

  //Door lock
  if (digitalRead(14) != lastStateLock && digitalRead(14) == LOW) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press('l');
    delay(10);
    Keyboard.releaseAll();
    lastStateLock = !lastStateLock;
  }

  //Door unlock
  if (digitalRead(14) != lastStateLock && digitalRead(14) == HIGH) {
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press('u');
    delay(10);
    Keyboard.releaseAll();
    lastStateLock = !lastStateLock;
  }
}
