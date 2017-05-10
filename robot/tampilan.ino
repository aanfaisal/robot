void baca(){
  
  //setting sound
  sensor=analogRead(sound);
  
  //setting button
  buttonState=digitalRead(button);
  
  //setting api
  kondisi1=digitalRead(api1);
  kondisi2=digitalRead(api2);
  kondisi3=digitalRead(api3);
  kondisi4=digitalRead(api4);
  kondisi5=digitalRead(api5);

  disi[0]=digitalRead(api1);
  disi[1]=digitalRead(api2);
  disi[2]=digitalRead(api3);
  disi[3]=digitalRead(api4);
  disi[4]=digitalRead(api5); 

  //setting garis
  gris1=analogRead(garis1);
  gris2=analogRead(garis2);


}

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
    lcd.print(disi[0]);
    lcd.setCursor(3,1);
    lcd.print(disi[1]);  
    lcd.setCursor(6,1);
    lcd.print(disi[2]);  
    lcd.setCursor(9,1);
    lcd.print(disi[3]);   
    lcd.setCursor(12,1);
    lcd.print(disi[4]);
    
    
    delay(100);lcd.clear();

}

