void maju() {
  digitalWrite(kiriMaju, HIGH);
  digitalWrite(kiriMundur, LOW);
  digitalWrite(kananMaju, HIGH);
  digitalWrite(kananMundur, LOW);
}

void mundur() {
  digitalWrite(kiriMaju, LOW);
  digitalWrite(kiriMundur, HIGH);
  digitalWrite(kananMaju, LOW);
  digitalWrite(kananMundur, HIGH);
}

void berhenti() {
  digitalWrite(kiriMaju, LOW);
  digitalWrite(kiriMundur, LOW);
  digitalWrite(kananMaju, LOW);
  digitalWrite(kananMundur, LOW);
}

void kanan() {
  digitalWrite(kiriMaju, LOW);
  digitalWrite(kiriMundur, LOW);
  digitalWrite(kananMaju, LOW);
  digitalWrite(kananMundur, HIGH);
}

void kiri() {
  digitalWrite(kiriMaju, LOW);
  digitalWrite(kiriMundur, HIGH);
  digitalWrite(kananMaju, LOW);
  digitalWrite(kananMundur, LOW);
}
