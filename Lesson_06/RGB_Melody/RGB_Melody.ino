void setup() {
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 262, 250);
  delay (250*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 196, 125);
  delay (125*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 196, 250);
  delay (125*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 220, 250);
  delay (250*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 196, 250);
  delay (250*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 247, 250);
  delay (250*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 247, 250);
  delay (250*1.30);

  analogWrite (9, random (0,255));
  analogWrite (10, random (0,255));
  analogWrite (11, random (0,255));
  tone(7, 262, 250);
  delay (250*1.30);
}

void loop() {
  
}
