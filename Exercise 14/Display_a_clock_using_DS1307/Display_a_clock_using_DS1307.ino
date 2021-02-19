#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

void setup() {
  
    Serial.begin (9600);
    Wire.begin ();
    RTC.begin();
    
    if (! RTC.isrunning()) {
      Serial.println("RTC is NOT running!");
      RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop() {
    DateTime now = RTC.now();
    Serial.print (now.month (), DEC);
    Serial.print ('/');
    Serial.print (now.day (), DEC);
    Serial.print ('/');
    Serial.print (now.year (), DEC);
    Serial.print (' ');
    Serial.print (now.hour (), DEC);
    Serial.print (':');
    Serial.print (now.minute (), DEC);
    Serial.print (':');
    Serial.print (now.second (), DEC);
    Serial.println ();
    delay (1000);

}
