#include <DHT.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

#define buzz A0
#define DHT1PIN 2
#define DHT2PIN 3
#define DHT1TYPE DHT11 
#define DHT2TYPE DHT11

DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);//Pin, Jenis DHT
SoftwareSerial bluetooth(0,1);//RX,TX; arduino TX0,RX1
//SoftwareSerial bluetooth(1,0);
char Data;
char buzzer = 0;
void sendData(String trasmitData){
  bluetooth.println(trasmitData);//kalo gak kebaca di ganti Serial.println(trasmitData)
}


void setup() {

  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
  pinMode(buzz,OUTPUT);
  digitalWrite(buzz, LOW);
}


void loop() {
  float kelembaban = dht1.readHumidity();
  float suhu = dht1.readTemperature();
  float kelembaban2 = dht2.readHumidity();
  float suhu2 = dht2.readTemperature();

  if (isnan(kelembaban) || isnan(suhu) ) {
    Serial.println("Failed to read from DHT");
  } 
  else {
 
    if (suhu >= 35){
      Serial.println(suhu);
      Serial.println("|");
      Serial.println("KEBAKARAN DI DAPUR");
      Serial.println("|");
      digitalWrite(buzz,HIGH);
      }
    if (suhu < 35){
      Serial.println(suhu);
      Serial.println("|");
      Serial.println("DAPUR AMAN");
      Serial.println("|");
    
    }

     if (suhu2 >= 35){
      Serial.println(suhu2);
      Serial.println("|");
      Serial.println("KEBAKARAN DI RUANG TAMU");
      Serial.println("|");
      digitalWrite(buzz,HIGH);
      }
    if (suhu2 < 35){
      Serial.println(suhu2);
      Serial.println("|");
      Serial.println("RUANG TAMU AMAN");
      Serial.println("|");
      
    }
    
    delay(4000);
  }
}
