void lamp(){
   
    //deteksi api  
        Serial.println("Api Terdeteksi");
        Serial.println("LED dan Pompa Nyala");
        
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

        
//        analogWrite(pompa, LOW);
        pwm.setPWM(motor, 0, pulseWidth(0)); //motor
        delay(kondisi3);
}

void api(){

        if( kondisi3==HIGH ){
        //analogWrite(pompa, HIGH);
        pwm.setPWM(motor, 0, pulseWidth(120)); //motor
        delay(kondisi3);
        }
        
        else if( kondisi3 == LOW){
            pwm.setPWM(motor, 0, pulseWidth(0)); //motor
            delay(kondisi3);
        }
  
}

void garis(){

    if(gris1 == HIGH || gris2 == HIGH)
    {
        //loop();
    }
    else if(gris1 == HIGH || gris2 == LOW)
    {
       // stanby2();
    }
  }
  
