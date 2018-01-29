void lamp() {
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
  
}

void api(){
  lamp();

  if(kondisi3 == 1) {
    analogWrite(motor, sepid);
    //       pwm.setPWM(motor, 0, pulseWidth(120)); //motor
    delay(kondisi3);
  }

  else if(kondisi3==0) {
    //         pwm.setPWM(motor, 0, pulseWidth(0)); //motor
    // algoritma();
    analogWrite(motor, LOW);
    delay(kondisi3);
  }

}

void garis(){
  if ((gris1<=250)||(gris2<=250))
  {
    standby1();
    //delay(1500);
  }
  else if ((gris1>=500)&&(gris1<=250))
  {
    maju();
    maju();
  }
}

