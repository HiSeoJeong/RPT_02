#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// 점멸횟수 변수 설정
int blinkNumber = 0;

void setup() {
  // 9600bps로 시리얼 통신 설정  
 Serial.begin(9600);
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.  
  // Arduino LCD, Welcome 표시  
  lcd.setCursor(0,0);
  lcd.print("Arduino LCD");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Welcome");
  delay(250);  
}
void loop() {
  if(Serial.available()){       
    char val = Serial.read();
    if(isDigit(val)){
      blinkNumber = (val - '0');
    }
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Message from PC");
    lcd.setCursor(0,1);
    lcd.print(blinkNumber);
      for(char i=0;i < blinkNumber;i++){
        lcd.noBacklight();
        delay(250);
        lcd.backlight();
        delay(250);
    }

while(Serial.available()>0) {
  lcd.write(Serial.read());
}

        
  }

}
