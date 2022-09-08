//Object detection with LCD, LED and buzzer
//@mahfuzur rahman Kiron 
//Coding Tips BD

#include <LiquidCrystal_I2C.h>
#define trigPin 9
#define echoPin 8
#define led1 7
#define led2 6
#define buzzer 5  
LiquidCrystal_I2C lcd(0x27, 16, 2);
int duration, distance;


void setup() {
  Serial.begin (9600);
  lcd.init();               // initialize the lcd
  lcd.backlight();
  pinMode(trigPin, OUTPUT); // config trigger pin to output mode
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  pinMode(buzzer, OUTPUT);
  noTone(buzzer);
             
}

void loop() {
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // measure duration of pulse from ECHO pin
  distance=0.017 * duration;// calculate the distance
  lcd.setCursor(0, 0);
  lcd.print("DISTANCE IN CM ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print("  CM");
  lcd.setCursor(0, 1);
  Serial.println(distance);
  
  if (distance < 6) {  // Here LED On/Off happens
  lcd.clear();
  digitalWrite(led1,HIGH);
  delay(1000);  
  lcd.print("  WARNING!!");
  lcd.setCursor(0, 1);
  lcd.print("OBSTACKLE DETECTED!");
  delay(2000);
  tone(buzzer, 300);
  delay(1000);
  lcd.clear();
  digitalWrite(led2,LOW);
  delay(2000);  
  noTone(buzzer);  
  lcd.setCursor(0,1);
  Serial.println("  WARNING!!");
  Serial.println("OBSTACKLE DETECTED!");
  
}
  else {
    
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }

  if (distance >= 100 || distance <= 0){
    
    Serial.println("Out of range");
    lcd.print("SENSOR IS OUT OF ");
    lcd.setCursor(0, 1);
    lcd.print("DETECTION RANGE");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    
  }
  delay(500);

}
  
