const int rl = 28;



void setup() {
  pinMode(rl, OUTPUT);
  digitalWrite(rl, HIGH);


}

void loop() {
   {
  digitalWrite(rl, LOW);
  delay(300);

  digitalWrite(rl, HIGH);
  delay(300);
  
}
}
