int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
int sensorThres = 300; //your threshold value.

void setup() // put your setup code here, to run once:
{
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(smokeA0,INPUT);
  Serial.begin(9600);
}

void loop()  // put your main code here, to run repeatedly:
{
  int analogSensor = analogRead(smokeA0);
  Serial.print(" Pin A0: ");
  Serial.println(analogSensor);
  //checks if it has reached the threshold value.
  if(analogSensor > sensorThres)
  {
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    tone(buzzer,1000,200);  //1000 peak sound value and 200 break b/w each bit.
  }
  else
  {
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    noTone(buzzer);
  }
   delay(100);
}
