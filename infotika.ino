#include <Servo.h>

Servo kepala;

#define SERVOPIN 10

#define kiriMaju 6
#define kiriMundur 7
#define kananMaju 4
#define kananMundur 5
#define EN1 12
#define EN2 13

#define TRIGPIN 8
#define ECHOPIN 9

int jarakDepan;

void setup() {
  Serial.begin(9600);

  pinMode(kiriMaju, OUTPUT);
  pinMode(kiriMundur, OUTPUT);
  pinMode(kananMaju, OUTPUT);
  pinMode(kananMundur, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

  kepala.attach(SERVOPIN);
  kepala.write(95);  // lihat depan
  delay(300);
}

void loop() {

  jarakDepan = bacaJarak();
  Serial.print("Jarak: ");
  Serial.print(jarakDepan);
  Serial.println(" cm");

  // ===========================
  // LOGIKA FOLLOW OBJECT
  // ===========================

  if (jarakDepan >= 20 && jarakDepan <= 60) {
    // objek berada di range follow
    analogWrite(EN1, 150);
    analogWrite(EN2, 150);
    maju();
    Serial.println("Mengikuti objek...");
  }
  else if (jarakDepan < 20) {
    // terlalu dekat → mundur
    analogWrite(EN1, 150);
    analogWrite(EN2, 150);
    mundur();
    Serial.println("Terlalu dekat, mundur...");
    delay(150);
    berhenti();
  }
  else {
    // tidak ada objek di range follow
    berhenti();
    Serial.println("Tidak ada objek dalam jarak follow.");
  }

  delay(80);
}
