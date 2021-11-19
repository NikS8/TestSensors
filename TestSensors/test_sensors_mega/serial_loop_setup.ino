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
  Serial.println("Если команда servoPin4, то запускается servo на 4 пине");
  Serial.println("Если команда servoPin5, то запускается servo на 5 пине");
  Serial.println("Если команда servoR, то запускается servoRight");
  Serial.println("Если команда servoL, то запускается servoLeft");
  Serial.println(" ");

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
