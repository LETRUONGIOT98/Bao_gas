
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int gas = A0;
#define nhac 4
#define relay 5
#define quat A1

LiquidCrystal_I2C lcd(0x3F,20,4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(nhac, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(quat, OUTPUT);
  digitalWrite(nhac, HIGH);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("    TRAN THI HON    ");
  lcd.setCursor(0, 1);
  lcd.print("   DANG KHOI DONG   ");
  lcd.setCursor(0, 2);
  lcd.print("    VUI LONG CHO!   ");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
int nongdo = map(analogRead(gas),0,1023,0,100);
lcd.setCursor(0, 1);
  lcd.print("NONG DO:        ppm");
  lcd.setCursor(9, 1);
  lcd.print(nongdo);
  if(nongdo >= 50){
    lcd.setCursor(0, 2);
  lcd.print("     CANH BAO!     ");
  lcd.setCursor(0, 3);
  lcd.print("PHAT HIEN RO KHI GAS");
    digitalWrite(quat, HIGH);
    digitalWrite(relay, LOW);
    digitalWrite(nhac, LOW);
    delay(100);
    digitalWrite(nhac, HIGH);
    Serial.println("ATD+84328813393;");
    delay(20000);
    Serial.println("ATH");
    delay(1000);
  }
  else{
    lcd.setCursor(0, 2);
  lcd.print("    BINH THUONG     ");
  lcd.setCursor(0, 3);
  lcd.print("KHONG KHI TRONG LANH");
    digitalWrite(quat, LOW);
    digitalWrite(relay, HIGH);
    digitalWrite(nhac, HIGH);
  }
  delay(100);
}
