const int backled = 3;
const int speedcontrol = 25;
const int drive = 2;

void setup() {

Serial.begin(9600);
pinMode(drive, OUTPUT);
pinMode(speedcontrol, OUTPUT);
pinMode(backled, OUTPUT);   
}

void loop() {

  delay(100);
  digitalWrite(drive, HIGH);
  analogWrite(speedcontrol, 75);
  delay(2000);

  digitalWrite(drive, LOW);
  analogWrite(speedcontrol, 85);
  analogWrite(backled, HIGH);
  delay(2500);
  digitalWrite(backled, LOW);
  
}
