const int pingPin = 23;
const int pingPini = 24;
const int backled = 3;
const int speedcontrol = 25;
const int drive = 2;
const int photocell = A3; 
const int light = 4;
const int outputpin = A2;
const int fan = 7;
const int rl = 28;
const int sensorValue(A1);


void setup() {
  // initialize serial communication:
    Serial.begin(9600);
    pinMode(pingPin, OUTPUT);
    pinMode(pingPini, INPUT);
    pinMode(drive, OUTPUT);
    pinMode(speedcontrol, OUTPUT);
    pinMode(backled, OUTPUT);
    pinMode(light, OUTPUT);
    pinMode(photocell, INPUT);
    pinMode(fan,OUTPUT);
    pinMode(rl, OUTPUT);
    pinMode(sensorValue, INPUT);
    digitalWrite(rl, HIGH);
    digitalWrite(fan, HIGH);
    
}

void loop()
{
//=========Activation====================================================
analogRead(sensorValue);
if(sensorValue > 1000)
{

//========Lights========================================================
  int value = analogRead(photocell);
  Serial.println("value = ");
  Serial.print(value);
  Serial.println();
  delay(50);

  if(value > 1000) //enter number given for value
  digitalWrite(light, HIGH);
  else
  digitalWrite(light, LOW);

//==========Fan=========================================================

  int rawvoltage= analogRead(outputpin);
  float millivolts= (rawvoltage/4096.0) * 3300; // for 3.3V Microcontroller
  float fahrenheit= millivolts/10;
  Serial.print(fahrenheit);
  Serial.print("F, ");
  Serial.println();

  if(fahrenheit > 80.00)
  {
    digitalWrite(fan, HIGH);
  }
  else
    digitalWrite(fan, LOW);
 
//=================Distance===============================================
 
  long duration, inches, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  duration = pulseIn(pingPini, HIGH);


  inches = microsecondsToInches(duration);
  
  Serial.print(inches);
  Serial.print("in");
  Serial.println();
  
//==============Drive==================================================
  if(inches > 20)
  {
  digitalWrite(drive, HIGH);
  analogWrite(speedcontrol, 80);
  digitalWrite(backled, LOW); 
  }
else 
{
  digitalWrite(drive, LOW);
  digitalWrite(rl, LOW);
  analogWrite(speedcontrol, 60);
  analogWrite(backled, HIGH);
  delay(700);  
  digitalWrite(rl, HIGH);
}
}
else
analogRead(sensorValue);
}

long microsecondsToInches(long microseconds)
{
   return microseconds / 74 / 2;
}

