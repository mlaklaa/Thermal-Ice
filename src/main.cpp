#include <Arduino.h>

#define SENSOR_PIN A0
#define TRANSISTOR_PIN 2
#define LED_PIN 13

bool isTransistorOn=false;


void setup() {
  pinMode(TRANSISTOR_PIN, OUTPUT);
  digitalWrite(TRANSISTOR_PIN, LOW);
}

void loop() {
  float temp=analogRead(A0);
  float temp_1=(temp*3.3)/1023;
  float temp2= (temp_1-0.5)*100;
  
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C | Stato carico: ");
  Serial.println(isTransistorOn ? "ATTIVO" : "SPENTO");

  if(temp2>=26 && !isTransistorOn){
    isTransistorOn=true;
    digitalWrite(TRANSISTOR_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("-> Soglia superata: Raffreddamento ATTIVATO");
  }else if (temp2<26 && isTransistorOn){
    isTransistorOn=false;
    digitalWrite(TRANSISTOR_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("-> Temperatura Rientrata: Raffreddamento DISATTIVATO");
  }
  delay (500);
}
