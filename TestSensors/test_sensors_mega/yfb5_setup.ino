/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup YF-B5 Interrupt
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void yfb5InterruptSetup() {

  pinMode(PIN_INTERRUPT_YFB5_BT, INPUT);
  //digitalWrite(PIN_INTERRUPT_YFB5_BT, HIGH);
  enableInterrupt(PIN_INTERRUPT_YFB5_BT, yfb5PulseCounterBT, FALLING);
  pinMode(PIN_INTERRUPT_YFB5_TA, INPUT);
  //digitalWrite(PIN_INTERRUPT_YFB5_TA, HIGH);
  enableInterrupt(PIN_INTERRUPT_YFB5_TA, yfb5PulseCounterTA, FALLING);
  
  sei();

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/