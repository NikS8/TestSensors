/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup Loop for serial
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 void menuTest() {

  Serial.println("Старт тестирования");
  Serial.println(" ");
  Serial.println("В мониторе надо выставить NL" );
  Serial.println(" ");
  Serial.println("Если команда i2c, то запускается I2C Scanner");
  Serial.println("Если команда ds18, то запускается ds18 Scanner");
  Serial.println("Если команда yfb5Pin2, то запускается yfb5 на 2 пине");
  Serial.println("Если команда yfb5Pin3, то запускается yfb5 на 3 пине");
  Serial.println("Если команда servoPin4, то выбирается servo на 4 пине");
  Serial.println("Если команда servoPin5, то выбирается servo на 5 пине");
  Serial.println("Если команда servoR, то запускается servoRight");
  Serial.println("Если команда servoL, то запускается servoLeft");
  Serial.println("Если команда relay, то выбирается relay");
  Serial.println(" ");

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
