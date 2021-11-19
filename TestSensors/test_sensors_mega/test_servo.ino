/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup Loop for serial
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void servoRight() {
 //   int pos = 0;    // variable to store the servo position

  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);    // tell servo to go to position in variable 'pos'
    delay(15);             // waits 15 ms for the servo to reach the position

Serial.print(" Позиция  servoRight = ");
Serial.println(pos);
 
  }
}

void servoLeft() {
 //   int pos = 0;    // variable to store the servo position

  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);     // tell servo to go to position in variable 'pos'
    delay(15);              // waits 15 ms for the servo to reach the position

Serial.print(" Позиция  servoLeft = ");
Serial.println(pos);
 
  }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
