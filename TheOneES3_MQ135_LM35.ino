float temp;
int tempPin = A0;
int sensorThres = 400; 

void setup() 
{
  //lcd.begin(16, 2);
  //lcd.setCursor(0, 0);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A1, INPUT);
  //delay(1000);
  Serial.begin(9600);
}

void loop() 
{
  int analogSensor = analogRead(A1);

 
  Serial.print(analogSensor);
  Serial.print(",");
  if(analogSensor > sensorThres)
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    tone(8, 1000, 200);
  }

  else
  {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    noTone(8);
  }
  
 
  temp = analogRead(tempPin);
  temp = (temp/1024) * 310;
  Serial.println(temp);
  delay(2000);
  
  if(temp <= 37)    
  {
     digitalWrite(7, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(5, LOW);     
  }
  
  else if(temp >= 37 && temp <= 40) 
  {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
  
  else if (temp >= 41)
  {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  
}
