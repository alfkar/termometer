#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE 11 

DHT dht (DHTPIN, DHTTYPE);
float temp;
float humid;
float heatindex;
float threshold;


void setup() {
  Serial.begin(9600);
  dht.begin();
  threshold = 50;
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  humid = dht.readHumidity();
  temp = dht.readTemperature();
  
  if (isnan(temp)){
    Serial.print(F("Temperature reading failed"));
  }
  //else if(temp < threshold){
    Serial.print(F("\nTemperature: "));
    Serial.print(temp);
    Serial.print(F(" C,"));
    //threshold = temp;
  //}
  /*
  heatindex = dht.computeHeatIndex(temp, humid);
  if (isnan(humid)){
    Serial.print(F("Humidity reading failed"));
  }
  else {
    Serial.print(F("\nHumidity: "));
    Serial.print(humid);
  }
  if (isnan(temp)){
    Serial.print(F("Temperature reading failed"));
  }
  else {
    Serial.print(F("% \nTemperature: "));
    Serial.print(temp);
    Serial.print(F(" C "));
  }
  if(!(isnan(humid)||isnan(temp))){
    Serial.print(F("\nHeat Index: "));
    Serial.print(heatindex);
    Serial.print(F(" C"));
    
  }
 */
  

}