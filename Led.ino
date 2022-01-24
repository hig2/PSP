const int ledPin = 6;

void initLed(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void ledRend(){
  switch (globalState[4]){
    case 0:
      digitalWrite(ledPin, HIGH); // горит
    break;
    case 1:
      ledBlink_2(200, 1000); // двойное мигание
    break;
    case 2:
      ledBlink(800);// мигает
    break;

  }
}

void ledBlink(int timer){
  static unsigned long t = 0;
  static bool timerFlag = false;
  
  if(millis() - t > timer){
    t = millis();
    timerFlag = !timerFlag;
    digitalWrite(ledPin, timerFlag);
  }
}

void ledBlink_2(int timer_1, int timer_2){
  static unsigned long t = 0;
  static bool timerFlag = false;
  static int blinkCount = 2 ;
  static bool timerFlag_2 = false;

  
  if(millis() - t > timer_1 && !timerFlag){
    t = millis();
    
    timerFlag_2 = !timerFlag_2;
    digitalWrite(ledPin, timerFlag_2);
    if(!timerFlag_2){
      blinkCount--;
    }
    if(blinkCount == 0){
      timerFlag = true;
    }  
    }else if(millis() - t > timer_2 && timerFlag){
      t = millis();
      timerFlag = false;
      blinkCount = 2;
    }
}
