/* 
 *  Program:  Demo av hvordan arduino lager analog spenning.  
 *  Version:  0.2
 *  Author:   Niko
 *  Date:     25/03/2022
 *  Desc:     Andre versjon - Oppdatert med inngangspenning, map og utskrift.
 */

#define analogVoltageOutPin 3  // 3 blir analogVoltageOutPin
#define potmeterInputPin A0    // A0 blir potmeterInputPin

void setup() { 
  Serial.begin(9600); // Bytes per sekund 
  
  pinMode(analogVoltageOutPin, OUTPUT); // aVOP er outputen
  pinMode(potmeterInputPin, INPUT);     // potmIP er input
}

void loop() {
  int potmeterRead = analogRead(potmeterInputPin); 
  Serial.print("PotmeterRead: ");
  Serial.println(potmeterRead); 

  float voltageIn = (5.0 / 1024.0) * potmeterRead;
  Serial.print("VoltageIn: "); 
  Serial.println(voltageIn); 

  byte analogWriteSetPoint = map(potmeterRead, 0, 1023, 0, 255); 
  Serial.print("AnalogWriteSetPoint: "); 
  Serial.println(analogWriteSetPoint); 

  float voltageOut = (5.0/256)*analogWriteSetPoint;
  Serial.print("VoltageOut: ");
  Serial.println(voltageOut); 

  analogWrite(analogVoltageOutPin, analogWriteSetpoint);

  Serial.println();
  delay(5000);
}