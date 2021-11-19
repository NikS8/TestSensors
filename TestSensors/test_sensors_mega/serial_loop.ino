/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Loop for serial
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void serialLoop() {

  if (Serial.available() > 0) {
    Serial.println("Старт тестирования");
    Serial.println();
    Serial.println("В мониторе надо выставить NL" );
    Serial.println();
    Serial.println("Если команда i2c, то запускается I2C Scanner");
    Serial.println("Если команда ds18, то запускается ds18 Scanner");
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();

    String commandin = "";
    char charcom;
    while (Serial.available()) {
      charcom = Serial.read();
      commandin.concat(charcom);
    }
    Serial.print(" command  = ");
    Serial.println(commandin);

    if (commandin == "i2c\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      Serial.println("i2c_scanner");
      i2c_scanner();
      return;
    }

    if (commandin == "ds18\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      Serial.println("dsMultiBus_scanner");
      dsMultiBus_scanner();
      return;
    }

  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/