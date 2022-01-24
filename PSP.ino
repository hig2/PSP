//PSP Контроль системы портативного питания 
//v1.0.0
#include <GyverWDT.h>

int globalState[10] = {
  0, //0- Статус положения защиты (0 - защита включенна, 1 - защита выключена)
  0, //1- Защита (0 - не сработала , 1 - сработала )
  16, //2- Порог срабатывания защиты (В)
  21 , //3-  Текущее напряжение
  0, //4- лед статус (0 - защита включена, 1 - защита выключена, 2 - защита)
  0, //5-
  0, //6-
  0, //7-
  0, //8-
  0  //9-
};


void setup(){
  initKey(1000);
  initButton();
  initLed();
  Watchdog.enable(RESET_MODE, WDT_PRESCALER_512);
  uart.begin(9600);
}

void loop(){
  buttonWatcher();
  ledRend();
  
  if(globalState[0] == 0){
    if(globalState[1] == 1){
      // защита сработала ключи закрыты 
       runKey(false);
       globalState[4] = 2;
    }else{
      // защита включена ключи открыты
       runKey(true);
       globalState[4] = 0;
    }
  }else if(globalState[0] == 1){
     // защита отключена ключи открыты
    globalState[4] = 1;
    globalState[1] = 0;
    runKey(true);
  }

  adcWatcher(500);
  Watchdog.reset();
}
