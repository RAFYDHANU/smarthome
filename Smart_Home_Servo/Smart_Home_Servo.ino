
#define BLYNK_PRINT Serial // definisi di gunakan 

#include <ESP8266WiFi.h> // file untuk modul wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk
#include <Servo.h>

//setting 
char auth[] = "-GXQoie3o8On4IlemNejA_N003nRpC8e"; // token yang dikirim dari blynk ke email masing"
char ssid[] = "Dhanu";
char pass[] = "masalupa";

// definisi fungsi servo menjadi gerak_servo
Servo gerak_servo;


BLYNK_WRITE(V1)
{
  // Debug console
  gerak_servo.write(param.asInt());
} // Fungsi Blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk


void setup()
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan boudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan passwordnya 

  gerak_servo.attach(2); // setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run(); // memulai blynk
}
