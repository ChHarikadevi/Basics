#include <LiquidCrystal.h>
int tempin = 0;
float voltage;
float temp;
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  lcd.begin(16, 2);
}

void loop()
{
  if (Serial.available()>0)
  {
  int x = Serial.read();
  if(x == 'F')
  {
  digitalWrite(11, 1);
  digitalWrite(10, 0);
  digitalWrite(9, 1);
  digitalWrite(8, 0);
  Serial.println("FORWARD");
  lcd.setCursor(2, 0);
  lcd.print("FORWARD");
  delay(2000);
  }
  if(x == 'B')
  {
  digitalWrite(11, 0);
  digitalWrite(10, 1);
  digitalWrite(9, 0);
  digitalWrite(8, 1);
  Serial.println("BACKWARD");
  lcd.setCursor(2, 0);
  lcd.print("BACKWARD");
  delay(2000);
  }
  if(x == 'R')
  {
  digitalWrite(11, 1);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  Serial.println("RIGHT");
  lcd.setCursor(2, 0);
  lcd.print("RIGHT");
  delay(2000);
  }
  if(x == 'L')
  {
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 1);
  digitalWrite(8, 0);
  Serial.println("LEFT");
  lcd.setCursor(2, 0);
  lcd.print("LEFT");
  delay(2000);
  }
  if(x == 'S')
  {
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  Serial.println("STOP");
  lcd.setCursor(2, 0);
  lcd.print("STOP");
  delay(2000);
  }
  }
  voltage = analogRead(tempin);
  voltage = voltage * 0.0048828125;
  temp = (voltage - 0.5)* 100.0;
  Serial.print("Temperature = ");
  Serial.print(temp); 
  Serial.println("C");
  lcd.setCursor(0, 0);
  lcd.print("TEMPERATURE IN C");
  lcd.setCursor(2, 1);
  lcd.print(temp);
  delay(1000);
  lcd.clear();
  
  if (temp >= 40)
  {
   Serial.println("High Temperature Alert!!");
   lcd.setCursor(0,0);
   lcd.print("High Temperature");
   lcd.setCursor(2,1);
   lcd.print("Alert !!");
   delay(1000);
   lcd.clear();
  }
  digitalWrite(13,HIGH);
  delayMicroseconds(10);
  digitalWrite(13,LOW);

  long duration = pulseIn(12,HIGH);
  long distance = duration*0.034/2;
  if(distance <= 25)
  {
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  Serial.print("Object detected at ");
  Serial.print(distance);
  Serial.println("CM");
  lcd.setCursor(0, 0);
  lcd.print("OBJECT DETECTED");
  lcd.setCursor(2, 1);
  lcd.print("AT ");
  lcd.print(distance);
  lcd.print(" CM");
  delay(2000);
  lcd.clear();
  }
}

