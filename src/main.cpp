#include <Arduino.h>

#define SENSOR_PIN A0
#define RELAY_PIN 2
#define LED_PIN 13

bool isRelayOn=false;
const float BETA=3950;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int temp=analogRead(A0);
  float temp_1= 1 / (log(1 / (1023.0 / temp - 1)) / BETA + 1.0 / 298.15) - 273.15; // poichè si tratta di un sensore NTC, la formula per calcolare la temperatura in gradi Celsius è la seguente:
  
  
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C | Stato carico: ");
  Serial.println(isRelayOn ? "ATTIVO" : "SPENTO");

  if(temp_1>=26 && !isRelayOn){
    isRelayOn=true;
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("-> Soglia superata: Raffreddamento ATTIVATO");
  }else if (temp_1<26 && isRelayOn){
    isRelayOn=false;
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("-> Temperatura Rientrata: Raffreddamento DISATTIVATO");
  }
  delay (200);
}
