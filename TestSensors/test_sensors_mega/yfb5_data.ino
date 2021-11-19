/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            function to measurement flow water
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int getFlowDataBT() {

  unsigned long flowSensorPulsesPerSecondBT;
  unsigned long deltaTime = millis() - sensorPulseLastTimeBT;

  if (deltaTime < 15000)  {
    return;
  }
  flowSensorPulsesPerSecondBT = sensorPulseCountBT * 15000 / deltaTime;
  sensorPulseLastTimeBT = millis();
  sensorPulseCountBT = 0;

Serial.print(" YF-B5 pin2 к-во импульсов за 15сек = ");
Serial.print(flowSensorPulsesPerSecondBT);

  return flowSensorPulsesPerSecondBT;
}

  int getFlowDataTA()
  {
  unsigned long flowSensorPulsesPerSecondTA;
  unsigned long deltaTime = millis() - sensorPulseLastTimeTA;

  if (deltaTime < 15000)  { 
    return; 
    }
  flowSensorPulsesPerSecondTA = sensorPulseCountTA * 15000 / deltaTime;
  sensorPulseLastTimeTA = millis();
  sensorPulseCountTA = 0;

Serial.print(" YF-B5 pin3 к-во импульсов за 15сек = ");
Serial.print(flowSensorPulsesPerSecondTA);

  return flowSensorPulsesPerSecondTA;
  }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/