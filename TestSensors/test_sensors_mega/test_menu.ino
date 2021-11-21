/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Меню тестовых команд
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void testMenuCommands() {
  // макрос F сохраняет текст во флеш память
  Serial.println(F("******************************"));
  Serial.println(F("Команды через Serial:"));
  Serial.println(F("     i2c start "));
  Serial.println(F("     ds18 start "));
  Serial.println(F("     hcsr04 start "));
  Serial.println(F("     press start "));
  Serial.println(F("set_pinServo 4 ... 5"));
  Serial.println(F("set_pinYFB5 2 ... 3"));
  Serial.println(F("set_pinRelay 24 ... 31"));
  Serial.println(F("set_speak 1 ... 15"));
  Serial.println(F("set_value 0 or 1"));  

  Serial.println(F("    get_value "));
  Serial.println(F("******************************"));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/