/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup httpServer
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void servo996rSetup() {
  myservo.attach(PIN_SERVO);  // attaches the servo on pin 9 to the servo object

  servo996in.attach(PIN_SERVO_IN);	  // сервопривод на 4 пине
  servo996out.attach(PIN_SERVO_OUT);  // сервопривод на 5 пине
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/