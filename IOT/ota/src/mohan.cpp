#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "M12"  // Replace with your network credentials
#define STAPSK  "mohan2003"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int a,b,c;
int z;
 
void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}
 
void OTAloop() {
  ArduinoOTA.handle();
}
 
//-------------------------------------------------------//
 
void setup(){
  OTAsetup();
 
  //-------------------//
  // Custom setup code //
  //-------------------//
        pinMode(4,INPUT);       
        pinMode(5,INPUT);
        pinMode(6,INPUT);
        pinMode(2,OUTPUT);
}
void disp(int z){                  
       digitalWrite(2,z);
}

void loop() {
	OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
        
        a = digitalRead(4);
        b = digitalRead(5);
        c = digitalRead(6);
        z=a||(!b && c);
// disp(z);
       digitalWrite(2,z);
} 
