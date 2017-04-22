void tampil(){
  //sensor 1 
   digitalWrite(trig_pin,LOW);
   delayMicroseconds(2);
   digitalWrite(trig_pin,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig_pin,LOW);
   pulse=pulseIn(echo_pin,HIGH);
   cm0=pulse/58.138;
  
  //sensor 2
   digitalWrite(trig_pin1,LOW);
   delayMicroseconds(2);
   digitalWrite(trig_pin1,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig_pin1,LOW);
   pulse1=pulseIn(echo_pin1,HIGH);
   cm1=pulse1/58.138;
   
  //sensor 3 
   digitalWrite(trig_pin2,LOW);
   delayMicroseconds(2);
   digitalWrite(trig_pin2,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig_pin2,LOW);
   pulse2=pulseIn(echo_pin2,HIGH);
   cm2=pulse2/58.138;
  
  //sensor 4
   digitalWrite(trig_pin3,LOW);
   delayMicroseconds(2);
   digitalWrite(trig_pin3,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig_pin3,LOW);
   pulse3=pulseIn(echo_pin3,HIGH);
   cm3=pulse3/58.138;
  
  //sensor 5
   digitalWrite(trig_pin4,LOW);
   delayMicroseconds(2);
   digitalWrite(trig_pin4,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig_pin4,LOW);
   pulse4=pulseIn(echo_pin4,HIGH);
   cm4=pulse4/58.138; 
  
   kondisi1=analogRead(flame1);
   kondisi2=analogRead(flame2);
   kondisi3=analogRead(flame3);
   kondisi4=analogRead(flame4);
   kondisi5=analogRead(flame5); 
  
    lcd.setCursor(0,0);
    lcd.print(cm0);//
    lcd.setCursor(3,0);
    lcd.print(cm1);  //
    lcd.setCursor(6,0);
    lcd.print(cm2);  //
    lcd.setCursor(9,0);
    lcd.print(cm3);   //
    lcd.setCursor(12,0);
    lcd.print(cm4);  //
  
  //set cursor tampilan flame
    lcd.setCursor(0,1);
    lcd.print(kondisi1);
    lcd.setCursor(3,1);
    lcd.print(kondisi2);  
    lcd.setCursor(6,1);
    lcd.print(kondisi3);  
    lcd.setCursor(9,1);
    lcd.print(kondisi4);   
    lcd.setCursor(12,1);
    lcd.print(kondisi5);
    
  //set tampilan sound
    lcd.setCursor(14,1);
    lcd.print(sensor);
    
    delay(100);lcd.clear();

}

