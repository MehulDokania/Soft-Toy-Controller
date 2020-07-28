/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(6,9);
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int trigPin =12, echoPin = 13;
int cal=0,c=0,distance;
long duration;
int change=0;
bool intro = true;
const int red=7;
const int green=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("No. of mails:");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
  ArduinoUno.begin(4800);
}

void loop() 
{
  Serial.println(c);
  ArduinoUno.print(c);
  ArduinoUno.println("\n");
  
  
  if(intro)
  {
    lcd.setCursor(0,0);
    lcd.print("Project made by:");
    lcd.setCursor(0,1);
    lcd.print("IED NINE-NINE");
    delay(5000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mail Box");
    delay(5000);
    lcd.clear();
    intro=false;
  }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,0);
  lcd.print("No. of mails:");
  lcd.setCursor(0, 1);
  lcd.print(c);
  /*----------------------------*/
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  if(distance<=6)
  {
    ++c;
    delay(500);
  }
  if(c>0)
  {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }
  else
  {
    digitalWrite(green,HIGH);
  }
  if(change!=c)
  {
    change=c;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Thankyou!");
    lcd.setCursor(0,1);
    lcd.print("For the mail.");
    delay(3000);
    lcd.clear();
  }
  
}
