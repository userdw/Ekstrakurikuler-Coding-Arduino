#include <Servo.h>
Servo myservo;
const int trigPin = 4;
const int echoPin = 5;
const int btnPin = 7;
const float batasJarak = 5.0;
bool btnState = false;
bool lastTime = millis();
float jarak;

float detectRange()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long tmeduration = pulseIn(echoPin, HIGH);
  float dis = (0.034 * tmeduration) / 2;
  return dis;
}

void setup() {
  // put your setup code here, to run once:
  myservo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(btnPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(btnPin);
  jarak = detectRange();
  Serial.println(jarak);
  if (btnState)
  {
    lastTime = millis();
    myservo.write(90);
  }
  else if (jarak > batasJarak)
  {
    myservo.write(0);
  }
}
