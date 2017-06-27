void setup()
{
Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A1);
  Serial.println(sensorValue); //  // print out the value you read:

  if (sensorValue > 750)
  Serial.println("active");
}

