/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Loop for serial
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void serialLoop() {

  if (Serial.available() > 0) {

    String commandin = "";
    char charcom;

    delay(444);

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
    }

    if (commandin == "ds18\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      Serial.println("dsMultiBus_scanner");
      dsMultiBus_scanner();
    }

    if (commandin == "servoPin4\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      PIN_SERVO = servoPin4;
    }
    
    if (commandin == "servoPin5\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      PIN_SERVO = servoPin5;
    }

    if (commandin == "servoR\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      Serial.println("servoRight");
      servoRight();
    }

    if (commandin == "servoL\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      Serial.println("servoLeft");
      servoLeft();
    }

  menuTest();

  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/