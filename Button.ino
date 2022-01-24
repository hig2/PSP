const int buttonPin = 2;

void initButton(){
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void buttonWatcher(){
  static unsigned long t = 0;
  static bool buttonPressFlag = false;
  static bool buttonPressFlag_2 = false;
  const int timePressButton = 200;
  if(!digitalRead(buttonPin)){
    if(!buttonPressFlag){
      t = millis();
      buttonPressFlag = true;
    }else if(millis() - t > timePressButton && !buttonPressFlag_2){
      if(globalState[0] == 0){
        globalState[0] = 1;
      }else{
        globalState[0] = 0;
      }
      buttonPressFlag_2 = true;
    }  
  }else{
    buttonPressFlag = false;
    buttonPressFlag_2 = false;
  }
}
