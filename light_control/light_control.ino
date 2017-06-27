const int photocell = A3; //a0-a11, analog to digital
const int light = 4; //digital pin

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(photocell, INPUT);
  

}

void loop() {
  int value = analogRead(photocell);
  Serial.println("value = ");
  Serial.println(value);
  delay(100);

  if(value > 1000) //enter number given for value
  digitalWrite(light, HIGH);
  else
  digitalWrite(light, LOW);
  
  }
