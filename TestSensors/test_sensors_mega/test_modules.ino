/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            test Modules for serial
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void testModules() {

    // опросчик и парсер сериал
  if (Serial.available() > 0) {           // проверка данных на вход
    String buf = Serial.readString();     // читаем как string
    // механизм такой: командой startsWith сравниваем начало строки
    // если совпадает - делаем какие то действия
    // для приёма значений используется такой механизм:
    // строка обрезается командой substring до длины команды .substring(команда.length())
    // оставшееся число преобразуется в число командой .toInt()
    
    if (buf.startsWith(menuCommands_s)) {
      menuCommands();
    }

    else if (buf.startsWith(i2c_start_s)) {
      valI2C = buf.substring(i2c_start_s.length()).toInt();
      Serial.print("i2c_start ");
      test_i2cScaner();
    }
    
    else if (buf.startsWith(ds18_start_s)) {
      valDS18 = buf.substring(i2c_start_s.length()).toInt();
      Serial.print("ds18_start ");
      test_ds18Scaner();
    }
    
    else if (buf.startsWith(setpinServo_s)) {
      pinServo = buf.substring(setpinRelay_s.length()).toInt();
      Serial.print("pinServo is ");
      Serial.print(pinServo);
      Serial.print(" and (0 = Left or 1 = Right) Left/Right is ");
      Serial.println(value);

      if (value == 1)
      {
      servoRight();
      }
      servoLeft();

      }    

    else if (buf.startsWith(setpinYFB5_s)) {
      pinYFB5 = buf.substring(setpinYFB5_s.length()).toInt();
      Serial.print("setpinYFB5 set to ");
      Serial.println(pinYFB5);

      if (pinYFB5 == 2)
      {
        Serial.print("Flow Data BT = ");    
        Serial.println(getFlowDataBT());    
      }
        Serial.print("Flow Data TA = ");    
        Serial.println(getFlowDataTA());           
    }

    else if (buf.startsWith(setpinRelay_s)) {
      pinRelay = buf.substring(setpinRelay_s.length()).toInt();
      Serial.print("pinRelay set to ");
      Serial.println(pinRelay);
      Serial.print("   is ");
      Serial.println(value);

      if (value == 0)
      {
          digitalWrite(pinRelay, LOW);    
      }
      digitalWrite(pinRelay, HIGH);  
      }    

    else if (buf.startsWith(setValue_s)) {
      value = buf.substring(setValue_s.length()).toInt();
      Serial.print("Value set to ");
      Serial.println(value);
    }

    else if (buf.startsWith(getValue_s)) {
  /*   Serial.print("Value is ");
      Serial.print("pinRelay is ");
      Serial.print(pinRelay);
       Serial.print("  Low/High is ");
      Serial.println(value);
      */
    }

      Serial.println("Value is ");
      Serial.print("pinServo is ");
      Serial.print(pinServo);
       Serial.print("  Left/Right is ");
      Serial.println(value);
      Serial.print("pinYFB5 is ");
      Serial.print(pinYFB5);
       Serial.print("   is ");
      Serial.println(value);
      Serial.print("pinRelay is ");
      Serial.print(pinRelay);
       Serial.print("  Low/High is ");
      Serial.println(value);

      menuCommands();

  } 

}
 

/*
/////////////////////
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
  menuTest();

  }
  */


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/