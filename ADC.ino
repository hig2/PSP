const int adcPin = A0;


void adcWatcher(int timer){
  static unsigned long t = 0;
  const float defVloltage = 5;
  if(millis() - t > timer){
    t = millis();
    float acc = 0.0;
    for(int i = 0; i < 10; i++){
      acc += ((analogRead(adcPin) * defVloltage) / 1024) / 0.0905;
    }
    acc = acc / 10;
    if(acc > 1){
      globalState[3] = acc;
    }else{
      globalState[3] = 0;
    }
  }
  uart.println(globalState[3]);
  if(globalState[3] < globalState[2]){
    globalState[1] = 1;
  }
}

void whileInitADC(int timer){
  unsigned long t = millis();
  while(t > millis()){
    adcWatcher(200);
  }
}
