int soilMoistureValue1 = 0;
int IN1 = 34;
int Pin1 = 13;

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "hN3ZdXhURen0vSlO8odthjEoB3na3IfU";

BlynkTimer timer;
char ssid[] = "SSID";
char pass[] = "Wifi-password";

void myTimerEvent()
{
  Blynk.virtualWrite(V34, analogRead(34));
}

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, myTimerEvent);
  pinMode(Pin1, OUTPUT);
  
  pinMode(IN1, INPUT);
  
  digitalWrite(Pin1, HIGH);
}

void loop()
{
   soilMoistureValue1 = analogRead(IN1);
   Serial.println(soilMoistureValue1);

   if (soilMoistureValue1 > 3500) {
       digitalWrite(Pin1, LOW);
   } else {
       digitalWrite(Pin1, HIGH);
   }
  delay(2000);
  Blynk.run();
  timer.run();
}
