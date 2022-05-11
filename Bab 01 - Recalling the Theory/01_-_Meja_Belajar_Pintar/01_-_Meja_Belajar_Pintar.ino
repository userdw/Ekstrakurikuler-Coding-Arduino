//Meja belajar pintar
int soundPin = A2; // inisialisasi sensor suara
int lightPin = A6; //inisialisasi sensor cahaya
int ledPin = 4; // inisialisasi LED

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
  pinMode(soundPin, INPUT);
}

void loop() {
  int soundState = analogRead(soundPin); // Membaca nilai sensor suara
  int lightState = analogRead(lightPin); // Membaca nilai sensor cahaya
  // jika nilai sensor suara lebih dari 500 atau nilai sensor suara kurang dari 200, maka LED akan menyala
  // begitu pula sebaliknya, LED akan padam
  if (soundState > 500 || lightState < 200) {
    digitalWrite(ledPin, HIGH);
    delay(500); //kamu dapat menambah simbol '//' untuk menonaktifkan delay 
  } else {
    digitalWrite(ledPin, LOW);
  }
}
