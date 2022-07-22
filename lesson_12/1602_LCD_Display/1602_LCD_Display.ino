#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
void setup() {
   lcd.begin (16,2);
   lcd.print ("Hello World");

}

void loop() {
  lcd.setCursor (0,1);
  lcd.print(millis()/1000);  
}
