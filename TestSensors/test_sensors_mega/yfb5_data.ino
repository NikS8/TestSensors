/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            function to measurement flow water
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int getFlowDataBT() {

  unsigned long flowSensorPulsesPerSecondBT;
  unsigned long deltaTime = millis() - yfb5LastTimeBT;

  if (deltaTime < 15000)  {
    return;
  }
  flowSensorPulsesPerSecondBT = yfb5PulseCountBT * 15000 / deltaTime;
  yfb5LastTimeBT = millis();
  yfb5PulseCountBT = 0;

  return flowSensorPulsesPerSecondBT;
}

int getFlowDataTA()
  {
  unsigned long flowSensorPulsesPerSecondTA;
  unsigned long deltaTime = millis() - yfb5LastTimeTA;

  if (deltaTime < 15000)  { 
    return; 
    }
  flowSensorPulsesPerSecondTA = yfb5PulseCountTA * 15000 / deltaTime;
  yfb5LastTimeTA = millis();
  yfb5PulseCountTA = 0;

  return flowSensorPulsesPerSecondTA;
  }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/