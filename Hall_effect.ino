
  volatile byte half_revolutions;
  unsigned int rpm;
  unsigned long timeold;
  void setup()
  {
    pinMode(3,OUTPUT);
    pinMode(2,INPUT);
    //Serial.begin(115200);
    attachInterrupt(0,rpm_fun,RISING);
    half_revolutions = 0;
    rpm=0;
    timeold=0;
    
  }
  void loop(){
    if (half_revolutions >=20)
    {
      rpm = 30*1000/(millis()- timeold)*half_revolutions;
      timeold=millis();
      half_revolutions=0;
      digitalWrite(3,LOW);
      
    }
  }
  void rpm_fun()
  {
    half_revolutions++;
    //Serial.println("detect");
    digitalWrite(3,HIGH);
    
  }
