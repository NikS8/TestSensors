/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            test ds18 Scaner (dsMultiBus scanner)
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void test_ds18Scaner() {
Serial.println("Dallas Temperature Multiple Bus Control Library Simple Demo");
  Serial.print("============Ready with ");
  Serial.print(oneWireCount);
  Serial.println(" Sensors================");
  
  // Start up the library on all defined bus-wires
  DeviceAddress deviceAddress;
  for (int i = 0; i < oneWireCount; i++) {;
    sensor[i].setOneWire(&ds18x20[i]);
    sensor[i].begin();
    if (sensor[i].getAddress(deviceAddress, 0)) sensor[i].setResolution(deviceAddress, 12);
  }

  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  for (int i = 0; i < oneWireCount; i++) {
    sensor[i].requestTemperatures();
  }
  Serial.println("DONE");
  
  delay(1000);
  for (int i = 0; i < oneWireCount; i++) {
      // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensor[i].isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  
    float temperature = sensor[i].getTempCByIndex(0);
    Serial.print("Temperature for the sensor ");
    Serial.print(i);
    Serial.print(" is ");
    Serial.println(temperature);
  }
  Serial.println();

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/