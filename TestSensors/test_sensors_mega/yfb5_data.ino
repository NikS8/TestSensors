/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            function to measurement flow water
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int getFlowDataBT() {

  unsigned long flowSensorPulsesPerSecondBT;
  unsigned long deltaTime = millis() - yfb5LastTimeBT;

  if (deltaTime < 15000)  {
    return;
  }
  flowSensorPulsesPerSecondBT = yfb5LastTimeBT * 15000 / deltaTime;
  yfb5LastTimeBT = millis();
  yfb5PulseCountBT = 0;

Serial.print(" YF-B5 pin2 к-во импульсов за 15сек = ");
Serial.println(flowSensorPulsesPerSecondBT);

  return flowSensorPulsesPerSecondBT;
}

  int getFlowDataTA()
  {
  unsigned long flowSensorPulsesPerSecondTA;
  unsigned long deltaTime = millis() - yfb5LastTimeTA;

  if (deltaTime < 15000)  { 
    return; 
    }
  flowSensorPulsesPerSecondTA = yfb5LastTimeTA * 15000 / deltaTime;
  yfb5LastTimeTA = millis();
  yfb5PulseCountTA = 0;

Serial.print(" YF-B5 pin3 к-во импульсов за 15сек = ");
Serial.println(flowSensorPulsesPerSecondTA);

  return flowSensorPulsesPerSecondTA;
  }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/