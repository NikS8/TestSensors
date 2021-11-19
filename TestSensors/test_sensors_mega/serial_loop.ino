/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Loop for serial
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void serialLoop() {
  
  if (Serial.available() > 0) {

     Serial.println("Старт тестирования");
      Serial.println("");
      Serial.println("Если команда i2c, то запускается I2C Scanner");
      Serial.println("Если команда ds18, то запускается I2C Scanner");
  

    // read the incoming byte:
    String incomingByte = "";
    incomingByte = Serial.read();

    if (millis() < 200) {
      return;
    }
    
    // enable all heaters by send "1" to serial
    // disable by any other char
    //Serial.println(incomingByte);
          if (incomingByte == "i2c") {
     i2c_scanner();
      Serial.println("i2c_scanner");
      return;
    }
           if (incomingByte == "ds18") {
   
      Serial.println("ON");
      return;
    }
 
    
    if (incomingByte == 49) {
      for (int i = 0; i < (sizeof(heaterStatePins) / sizeof(heaterStatePins[0])); i++) {
        digitalWrite(heaterStatePins[i], LOW);
      }
      Serial.println("ON");
      return;
    }
    if (incomingByte == 48) {
      for (int i = 0; i < (sizeof(heaterStatePins) / sizeof(heaterStatePins[0])); i++) {
        digitalWrite(heaterStatePins[i], HIGH);
      }
      Serial.println("OFF");
      return;
    }

    if (incomingByte == 50) {
      Serial.println("DS18 data:");
      for (uint8_t index = 0; index < ds18DeviceCountBD; index++) {
        DeviceAddress deviceAddress;
        ds18SensorsBD.getAddress(deviceAddress, index);
    
        for (uint8_t i = 0; i < 8; i++) {
          if (deviceAddress[i] < 16)  {
            // ??
          }
          Serial.print(String(deviceAddress[i], HEX));
        }
        Serial.print(": ");
        Serial.println(ds18SensorsBD.getTempC(deviceAddress));
      }
      return;
    }

    Serial.println("HELP: 0 - OFF all. 1 - ON all. 2 - print ds18 data");
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
