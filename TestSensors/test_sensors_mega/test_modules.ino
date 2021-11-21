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
    
    if (buf.startsWith(testMenuCommands_s)) {
      testMenuCommands();
    }
//
    else if (buf.startsWith(i2c_s)) {
      valI2C = buf.substring(i2c_s.length()).toInt();
      Serial.print("i2c_start ");
      test_i2cScaner();
    }
//    
    else if (buf.startsWith(ds18_s)) {
      valDS18 = buf.substring(ds18_s.length()).toInt();
      Serial.print("ds18_start ");
      test_ds18Scaner();
    }
//    
    else if (buf.startsWith(setpinServo_s)) {
      pinServo = buf.substring(setpinRelay_s.length()).toInt();
      Serial.print("pinServo is ");
      Serial.print(pinServo);
      Serial.print(" and (0 = Left or 1 = Right) Left(0)/Right(1) is ");
      Serial.println(value);

      if (value == 1)
      {
        servoRight();
      }
        servoLeft();
    }    
//
    else if (buf.startsWith(setpinYFB5_s)) {
      pinYFB5 = buf.substring(setpinYFB5_s.length()).toInt();
      Serial.print("setpinYFB5 set to ");
      Serial.println(pinYFB5);

      if (pinYFB5 == 2) {
        Serial.print("Flow Data BT = ");    
        Serial.println(getFlowDataBT());    
      }

      else if (pinYFB5 == 3) {
        Serial.print("Flow Data TA = ");    
        Serial.println(getFlowDataTA());  
      }

    }
//
    else if (buf.startsWith(setpinRelay_s)) {
      pinRelay = buf.substring(setpinRelay_s.length()).toInt();
      Serial.print("pinRelay set to ");
      Serial.print(pinRelay);
      Serial.print("   is ");
      Serial.println(value);
     
      if (value == 0) { 
        digitalWrite(pinRelay, LOW);   
      }

      else if (value == 1) {
        digitalWrite(pinRelay, HIGH);  
      }

    }    
//
    else if (buf.startsWith(relay_s)) {
      valRelay = buf.substring(relay_s.length()).toInt();
      Serial.println("   Relay is ");
      for (int i = 24; i < 32; i++) {
      Serial.print("  ");
      Serial.print(i);
      Serial.print(" = ");
      Serial.println(digitalRead(i));
      }
      
    }    
//
    else if (buf.startsWith(current_s)) {
      valCurrent = buf.substring(current_s.length()).toInt();
      String myemon = "emon";
      String mycur = "A";
      Serial.println("   current is ");
      for ( int i = 0; i < 7; i++)
      {        
        mycur += i;
        i += 1;
        myemon += i;
      Serial.print("       ");
      Serial.print(mycur); Serial.print(" = ");
      Serial.println(emon1.calcIrms(1480));
      myemon = "emon";
      mycur = "A";
      i -= 1;
      }
      
    }
//
    else if (buf.startsWith(setCurrent_s)) {
      valCurrent = buf.substring(setCurrent_s.length()).toInt();
      getCurrentCalibration();
    }
//
    else if (buf.startsWith(hcsr04_s)) {
      valHCSR04 = buf.substring(hcsr04_s.length()).toInt();
      Serial.print("hcsr04 distance = ");
      Serial.print(hcsr04.distanceInMillimeters());
      Serial.println(" mm ");
    }
//
    else if (buf.startsWith(press_s)) {
      valPress = buf.substring(press_s.length()).toInt();
     // Serial.print("press  = ");
      Serial.print(getPressureData());
      Serial.println(" bar ");
    }
//
    else if (buf.startsWith(setSpeak_s)) {
      valSpeak = buf.substring(setSpeak_s.length()).toInt();
      valSpeak = valSpeak * 1000;
      Serial.print("Speak is ");
      Serial.print(valSpeak);
      Serial.println(" Hz на 3 сек");
      tone (PIN_SPEAKER, valSpeak, 3000); //включаем на 3 сек
    //  delay(3000); //ждем 3 сek
      noTone(PIN_SPEAKER); // отключаем 
    }
//
    else if (buf.startsWith(setValue_s)) {
      value = buf.substring(setValue_s.length()).toInt();
      Serial.print("Value set to ");
      Serial.println(value);
    }
//
    else if (buf.startsWith(getValue_s)) {
  /*   Serial.print("Value is ");
      Serial.println(value);
      */
    }
//
      Serial.println("\n Acting variables is :");
            
      Serial.print("   pinsDS18 is ");
      Serial.print("  PIN_WIRE_BUS_BD = ");
      Serial.print(PIN_WIRE_BUS_BD);
      Serial.print("  PIN_WIRE_BUS_BT = ");
      Serial.print(PIN_WIRE_BUS_BT);
      Serial.print("  PIN_WIRE_BUS_TA = ");
      Serial.print(PIN_WIRE_BUS_TA);
      Serial.print("  PIN_WIRE_BUS_HP = ");
      Serial.println(PIN_WIRE_BUS_HP);

      Serial.print("   pinServo is ");
      Serial.print(pinServo);
      Serial.print("  Left(0)/Right(1) is ");
      Serial.println(value);

      Serial.print("   pinYFB5 is ");
      Serial.println(pinYFB5);

      Serial.print("   pinsHCSR04 is ");
      Serial.print("  PIN_TRIG = ");
      Serial.print(PIN_TRIG);
      Serial.print("  PIN_ECHO = ");
      Serial.println(PIN_ECHO);

      Serial.print("   pinPress is ");
      Serial.println(PIN_SENSOR_PRESSURE);

      Serial.print("   current is ");
      Serial.println("  A0 ... A6 ");

      Serial.print("   pinSpeak is ");
      Serial.print(PIN_SPEAKER);
      Serial.print("  tone ");
      Serial.print(valSpeak);
      Serial.println(" Hz ");

      Serial.print("   pinRelay is ");
      Serial.print(pinRelay);
      Serial.print("  Low(0)/High(1) is ");
      Serial.println(value);

      testMenuCommands();

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