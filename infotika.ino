#include <Servo.h>

Servo kepala;

#define SERVOPIN 7

#define kiriMaju 8
#define kiriMundur 9
#define kananMaju 10
#define kananMundur 11
#define EN1 12
#define EN2 13

#define TRIGPIN 5
#define ECHOPIN 6

int jarakDepan, jarakKiri, jarakKanan;

void clearSerial() {
  String clrscr = "";
  for (int i = 0; i < 100; i++) {
    clrscr += "\n";
  }

  Serial.print(clrscr);
}

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

  //  jarakDepan = bacaJarak();
  clearSerial();
}

void testing() {
  Serial.println("Sedang mengambil jarak depan....");
  delay(1000);
  Serial.print("Jarak depan = ");
  Serial.print(bacaJarak());
  Serial.println(" cm");
  delay(2000);

  clearSerial();
  delay(2000);
  kepala.write(175);
  delay(2000);

  Serial.println("Sedang mengambil jarak kiri....");
  delay(1000);
  Serial.print("Jarak kiri = ");
  Serial.print(bacaJarak());
  Serial.println(" cm");
  delay(2000);

  clearSerial();
  kepala.write(15);
  delay(2000);

  Serial.println("Sedang mengambil jarak kanan....");
  delay(1000);
  Serial.print("Jarak kanan = ");
  Serial.print(bacaJarak());
  Serial.println(" cm");
  delay(2000);

  clearSerial();
  kepala.write(95);
  delay(2000);
}

void looping() {
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
}

void loop() {
  // testing();

  looping();
}
