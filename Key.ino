const int enVccPin = 5;

void initKey(int msDelay){
  pinMode(enVccPin, OUTPUT);
  digitalWrite(enVccPin, LOW);
  //whileInitADC(1000); //задержка перед включением + "прогрев" АДС
  digitalWrite(enVccPin, HIGH);
}

void runKey(bool s){
   digitalWrite(enVccPin, s);
}
