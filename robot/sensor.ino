void api(){
  
 kondisi1=digitalRead(api1);
 kondisi2=digitalRead(api2);
 kondisi3=digitalRead(api3);
 kondisi4=digitalRead(api4);
 kondisi5=digitalRead(api5); 

    //deteksi api  
      if((kondisi1==HIGH)||(kondisi2==HIGH)||(kondisi3==HIGH)||(kondisi4==HIGH)||(kondisi5==HIGH))
      {
        Serial.println("Api Terdeteksi");
        Serial.println("LED dan Pompa Nyala");
        
        //analogWrite(pompa, HIGH);
        pwm.setPWM(motor, 0, pulseWidth(120)); //motor
        
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
      }
      else 
      {
       // analogWrite(pompa, LOW);
        pwm.setPWM(motor, 0, pulseWidth(0)); //motor
        delay(kondisi3);
      }

}

void garis(){
  gris1=analogRead(garis1);
  gris2=analogRead(garis2);
  gris3=analogRead(garis3);

    if(gris1 == HIGH || gris2 == HIGH || gris3==HIGH)
    {
        //loop();
    }
    else if(gris1 == HIGH || gris2 == LOW || gris3==HIGH)
    {
       // stanby2();
    }
  }
  
