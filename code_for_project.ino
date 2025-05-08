#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float temp;
int tempPin = A1;
int relayPin = 8;
#define fan 9
void setup()
{
    pinMode(fan, OUTPUT);
    pinMode(relayPin, OUTPUT); 
    lcd.begin(16, 3); 
    lcd.setCursor(0, 0);
    lcd.print(“AUTOMATIC FAN”);
    delay(2000);
    lcd.clear();
}
void loop()
{
  lcd.setCursor(3,0);
  lcd.print(“Recording”);
  lcd.setCursor(2, 1);
  lcd.print(“Temperature..”);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,2);
  temp = analogRead(tempPin);
  float voltage = temp * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage – 0.5) * 100 ;
  lcd.setCursor(0, 0);
  lcd.print(“Temperature = “);
  lcd.setCursor(2,1);
  lcd.print(temperatureC); lcd.println(“ degrees C”);
  delay(2000);
  lcd.clear();
 
 if(temperatureC >= 20)
  {
  poweronRelay();
    if(temperatureC >= 20 && temperatureC <= 25)
    {
      analogWrite(fan,51);
      lcd.setCursor(0, 1);
      lcd.print(“Fan Speed: 20% “);
      delay(2000);
      lcd.clear();
    }
    else if(temperatureC >25 && temperatureC <= 30)
    {
      analogWrite(fan,102);
      lcd.setCursor(0, 1);
      lcd.print(“Fan Speed: 40% “);
      delay(2000);
      lcd.clear();
    }
    else if(temperatureC>30 && temperatureC <= 35)
    {
      analogWrite(fan,153);
      lcd.setCursor(0, 1);
      lcd.print(“Fan Speed: 60% “);
      delay(2000);
      lcd.clear();
    }
    else if(temperatureC>35 && temperatureC <= 40)
    {
      analogWrite(fan,200);
      lcd.setCursor(0, 1);
      lcd.print(“Fan Speed: 80% “);
      delay(2000);
      lcd.clear();
    }
    else if(temperatureC > 40)
    {
      analogWrite(fan,255);
      lcd.setCursor(0, 1);
      lcd.print(“Fan Speed: 100% “);
      delay(2000);
      lcd.clear();
    }
  }
  else if(temperatureC < 20)
  {
  poweroffRelay();
  }
}
void poweronRelay()
  {
  digitalWrite(relayPin, HIGH);
    lcd.print(“Fan ON”);
  }
void poweroffRelay()
  {
  digitalWrite(relayPin, LOW);
  analogWrite(fan,0);
    lcd.print(“Fan OFF”);
    delay(1000);
    lcd.clear();
  }
