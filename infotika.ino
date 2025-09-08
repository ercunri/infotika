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

int jarakDepan, jarakKiri, jarakKanan;

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

  delay(100);
  kepala.write(95);
  bacaJarak();
  delay(500);

  bacaJarak();
  delay(500);

  jarakDepan = bacaJarak();
}

void loop() {
  if (jarakDepan != 0 && jarakDepan <= 20) {
    berhenti();
    delay(300);

    analogWrite(EN1, 200);
    analogWrite(EN2, 200);
    mundur();
    delay(100);

    berhenti();
    delay(300);

    jarakKanan = lihatKanan();
    delay(500);
    jarakKiri = lihatKiri();

    if (jarakKanan > jarakKiri) {
      kanan();
      delay(500);
      berhenti();
    } else {
      kiri();
      delay(500);
      berhenti();
    }
  } else {
    if (jarakDepan <= 40) {
      analogWrite(EN1, 150);
      analogWrite(EN2, 150);
    } else {
      analogWrite(EN1, 220);
      analogWrite(EN2, 220);
    }
    maju();
  }

  jarakDepan = bacaJarak();
  delay(50);

  //  Serial.print("Depan: ");
  //  Serial.println(bacaJarak());
  //  delay(500);
  //  Serial.print("Kanan: ");
  //  Serial.println(lihatKanan());
  //  delay(500);
  //  Serial.print("Kiri: ");
  //  Serial.println(lihatKiri());
  //  delay(500);
}
