/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup YF-B5 Interrupt
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void yfb5InterruptSetup() {

  pinMode(PIN_YFB5_IN_BT, INPUT);
  //digitalWrite(PIN_YFB5_IN_BT, HIGH);
  enableInterrupt(PIN_YFB5_IN_BT, yfb5PulseCounterBT, FALLING);

  pinMode(PIN_YFB5_IN_TA, INPUT);
  //digitalWrite(PIN_YFB5_IN_TA, HIGH);
  enableInterrupt(PIN_YFB5_IN_TA, yfb5PulseCounterTA, FALLING);
  
  sei();

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/