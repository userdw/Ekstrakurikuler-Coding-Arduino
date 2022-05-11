const int PIN_JOYX = A0;
const int PIN_JOYY = A1;
const int PIN_MOTOR_1 = 9;
const int PIN_MOTOR_2 = 10;
int CENTER = 0;

void setup(){
  pinMode(PIN_JOYX, INPUT);
  pinMode(PIN_JOYY, INPUT);
  pinMode(PIN_MOTOR_1, OUTPUT); 
  pinMode(PIN_MOTOR_2, OUTPUT); 
  
  digitalWrite(PIN_MOTOR_1, LOW);
  digitalWrite(PIN_MOTOR_2, LOW);
  CENTER = analogRead(PIN_JOYY) / 2;
}

void loop(){
  int val = (analogRead(PIN_JOYX) / 2) - CENTER;

  if (val > 0){
    analogWrite(PIN_MOTOR_1, val);
    digitalWrite(PIN_MOTOR_2, LOW);
  }
  else {
    digitalWrite(PIN_MOTOR_1, LOW);
    analogWrite(PIN_MOTOR_2, val);
  }
  delay(10);
}
