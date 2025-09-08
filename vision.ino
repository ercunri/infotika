int bacaJarak() {
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   

  long timer = pulseIn(ECHOPIN, HIGH);
  int jarak = timer * 0.034 / 2;

  return jarak;
}

int lihatKanan() {
  kepala.write(15);
  delay(500);

  int jarak = bacaJarak();

  delay(500);
  kepala.write(95);

  return jarak;
}

int lihatKiri() {
  kepala.write(175);
  delay(500);

  int jarak = bacaJarak();

  delay(500);
  kepala.write(95);

  return jarak;
}
