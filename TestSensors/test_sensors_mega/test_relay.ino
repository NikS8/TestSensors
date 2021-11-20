/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Loop for serial
  \*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
  /*
void relay() {
   
  String commandin = "";
  char charcom;
  int pin_relay = 24;

  for (int i = 24; i < 32; i++)
  {
    pinMode(i, OUTPUT);
    delay(111);
  }

  Serial.println("Введите команду HIGH или LOW");


  if (Serial.available() > 0) {


 
    delay(44);

    while (Serial.available()) {
      charcom = Serial.read();
      commandin.concat(charcom);
    }
    Serial.print(" command  = ");
    Serial.println(commandin);


    if (commandin == "HIGH\n") {
      Serial.print(" command  = ");
      Serial.println(commandin);
      Serial.println("Введите цифру от 1 до 9 ");
      Serial.println("Цифры от 1 до 8 это № реле, а цифра 9 это выход ");

      if (Serial.available() > 0) {
        int inpin = Serial.read();

        if (inpin <= '8') {

          pin_relay = 23 + inpin;
          digitalWrite(pin_relay, HIGH);
          Serial.print("digitalWrite(");
          Serial.print(pin_relay);
          Serial.println(", HIGH) ");
          return;
        }
        else if (pin_relay == '9') {
          menuTest();
        }
      }

///*
      if (commandin == "LOW\n") {
        Serial.print(" command  = ");
        Serial.println(commandin);
        Serial.println("Введите цифру от 1 до 9 ");
        Serial.println("Цифры от 1 до 8 это № реле, а цифра 9 это выход ");

        if (Serial.available() > 0) {
          int inpin = Serial.read();

          if (inpin <= '8') {

            pin_relay = 23 + inpin;
            digitalWrite(pin_relay, LOW);
            Serial.print("digitalWrite(");
            Serial.print(pin_relay);
            Serial.println(", LOW) ");
            return;
          }
          else if (pin_relay == '9') {
            menuTest();
          }
          else if (pin_relay == '0') {
            menuTest();
          }

     //     menuTest();



        }
        delay(10);

      }
//

    }

  }

}
*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void menuCommands() {
  // макрос F сохраняет текст во флеш память
  Serial.println(F("**************************************"));
  Serial.println(F("Команды через Serial:"));
  Serial.println(F("         get_value "));
  Serial.println(F("set_pinRelay 24 ... 31"));
  Serial.println(F("set_value 0 or 1"));
  Serial.println(F("**************************************"));
}
////////////////////////
// опросчик и парсер сериал
void relay() {
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

    else if (buf.startsWith(getpinRelay_s)) {
      Serial.print("pinRelay is ");
      Serial.println(pinRelay);
    }
    else if (buf.startsWith(setpinRelay_s)) {
      pinRelay = buf.substring(setpinRelay_s.length()).toInt();
      Serial.print("pinRelay set to ");
      Serial.println(pinRelay);
      }    
    else if (buf.startsWith(getValue_s)) {
      Serial.print("Value is ");
      Serial.print("pinRelay is ");
      Serial.print(pinRelay);
       Serial.print("   is ");
      Serial.println(value);
    }
    else if (buf.startsWith(setValue_s)) {
      value = buf.substring(setValue_s.length()).toInt();
      Serial.print("Value set to ");
      Serial.println(value);
    }
  }


      Serial.print("Value is ");
      Serial.print("pinRelay is ");
      Serial.print(pinRelay);
       Serial.print("   is ");
      Serial.println(value);

            digitalWrite(pinRelay, value);
}
///////