/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
                                                               boiler-down.ino
                                        Copyright © 2018-2021, Zigfred & Nik.S
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\                            
  Arduino MEGA 2560 PRO:
Скетч использует 35304 байт (13%) памяти устройства. Всего доступно 253952 байт.
Глобальные переменные используют 3018 байт (36%) динамической памяти, 
оставляя 5174 байт для локальных переменных. Максимум: 8192 байт.
/*****************************************************************************\
  Сервер boiler-down выдает данные:
    аналоговые: 
датчики трансформаторы тока (pins A1, A2, A3, A4, A5, A6, A7)
    цифровые:
датчик скорости потока воды YF-B5 (D2, D3)(количество импульсов за 15 сек)
датчики температуры DS18B20 (OneWire pin D41, D42, D43)
дальномер HC-SR04 (D22, D23)(измерение уровня воды)
датчик положения клапана от Servo996R (pins D4,D5)
    звуковые:
speak pin D46
/*****************************************************************************/

//  Блок DEVICE  --------------------------------------------------------------
//  Arduino MEGA 2560 PRO (ROBODYN)
#define DEVICE_ID "test-sensors-mega"
#define VERSION 2

//  Блок libraries  -----------------------------------------------------------
#include <Ethernet2.h>          //  httpServer (40102) pins D10,81,83,84,85
#include <Wire.h>               //  test ds18
#include <OneWire.h>            //  DS18B20 pins OneWire D41, D42, D43
#include <DallasTemperature.h>  //  DS18B20
#include <RBD_Timer.h>          //  DS18B20
#include <EmonLib.h>            //  трансформаторы тока pins A0 ... A7
#include <hcsr04.h>             //  HC-SR04  pins D22,D23
#include <Servo.h>              //  Servo996R pins D4,D5
#include <EnableInterrupt.h>    //  flow YF-B5 pins D2,D3
//                                speak pin D46

//  Блок settings  ------------------------------------------------------------
#include "test_sensors_mega_init.h"

//	end init  -----------------------------------------------------------------

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() {
  
  Serial.begin(9600);
  Serial.println("Serial.begin(9600)"); 
    delay (1000);
    
  Wire.begin();

  Serial.print(F("FREE RAM: "));
  Serial.println(freeRam());
  
  ds18b20Setup();
  yfb5InterruptSetup();
  currentSetup();
  servo996rSetup();
  relayModuleSetup();

  pinMode(PIN_SPEAKER, OUTPUT);
// test
  testMenuCommands();

//  

  delay (2000);
  httpServerSetup();

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {
  realTimeService();
  resetChecker();

  testModules();
  

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            info
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\

21.11.2021 v2 Интерфейс монитора порта
19.11.2021 v1

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            end
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
