/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Меню тестовых команд
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void menuCommands() {
  // макрос F сохраняет текст во флеш память
  Serial.println(F("******************************"));
  Serial.println(F("Команды через Serial:"));
  Serial.println(F("    get_value "));
  Serial.println(F("     get_i2c "));
  Serial.println(F("     get_ds18 "));
  Serial.println(F("set_pinServo 4 ... 5"));
  Serial.println(F("set_pinYFB5 2 ... 3"));
  Serial.println(F("set_pinRelay 24 ... 31"));
  Serial.println(F("set_value 0 or 1"));
  Serial.println(F("******************************"));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/