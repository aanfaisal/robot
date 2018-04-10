void standby1() {
  //kaki bagian A standby
  pwm.setPWM(kakiA1, 0, pulseWidth(90));
  delay(SPEED);
  pwm.setPWM(kakiA2, 0, pulseWidth(90));
  delay(SPEED);
  //kaki bagian B standby
  pwm.setPWM(kakiB1, 0, pulseWidth(90));
  delay(SPEED);
  pwm.setPWM(kakiB2, 0, pulseWidth(90));
  delay(SPEED);
  //kaki bagian C standby
  pwm.setPWM(kakiC1, 0, pulseWidth(90));
  delay(SPEED);
  pwm.setPWM(kakiC2, 0, pulseWidth(90));
  delay(SPEED);
  //kaki bagian D standby
  pwm.setPWM(kakiD1, 0, pulseWidth(90));
  delay(SPEED);
  pwm.setPWM(kakiD2, 0, pulseWidth(90));
  delay(SPEED);
}

// kalo menemukan api
void standby2() {
  //sweep
  pwm.setPWM(kakiA2, 0, pulseWidth(40));
  delay(SPEED);
  pwm.setPWM(kakiA1, 0, pulseWidth(60));//atasA
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiB2, 0, pulseWidth(40));
  delay(SPEED);
  pwm.setPWM(kakiB1, 0, pulseWidth(60));  //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiC2, 0, pulseWidth(40));
  delay(SPEED);
  pwm.setPWM(kakiC1, 0, pulseWidth(60));//atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiD2, 0, pulseWidth(40));
  delay(SPEED);
  pwm.setPWM(kakiD1, 0, pulseWidth(60));  //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));
}


//A = B ... C = D
/*.............gerakan memulai berjalan..............*/
//gerak maju______sweep di bagian maju
void maju() {
    //sweep A
    pwm.setPWM(kakiA2, 0, pulseWidth(60));
    delay(SPEED);
    //iki maju A
    pwm.setPWM(kakiA1, 0, pulseWidth(110)); //atasB 
    delay(SPEED);
    pwm.setPWM(kakiA2, 0, pulseWidth(90));
    delay(SPEED);
    pwm.setPWM(kakiA1, 0, pulseWidth(50)); //atasB
    delay(SPEED);

    //sweep C
    pwm.setPWM(kakiC2, 0, pulseWidth(60));
    delay(SPEED);
    //iki maju C
    pwm.setPWM(kakiC1, 0, pulseWidth(50)); //atasC
    delay(SPEED);
    pwm.setPWM(kakiC2, 0, pulseWidth(90));
    delay(SPEED);
    //iki mundur
    pwm.setPWM(kakiC1, 0, pulseWidth(110)); 
    delay(SPEED);
////...............batas suci........................//
//    
//  
    //sweep B
    pwm.setPWM(kakiB2, 0, pulseWidth(60));
    delay(SPEED);
//  //iki maju    
    pwm.setPWM(kakiB1, 0, pulseWidth(70)); //atasA   
    delay(SPEED);
    pwm.setPWM(kakiB2, 0, pulseWidth(90));
    delay(SPEED);
//iki mundur
    pwm.setPWM(kakiB1, 0, pulseWidth(40));
    //habis ni B mundur
    delay(SPEED);
    //sweep C
    pwm.setPWM(kakiD2, 0, pulseWidth(60));
    delay(SPEED);
    //iki maju 
    pwm.setPWM(kakiD1, 0, pulseWidth(80)); //atasC
    delay(SPEED);
    pwm.setPWM(kakiD2, 0, pulseWidth(90));
    delay(SPEED);
    //iki mundur
    pwm.setPWM(kakiD1, 0, pulseWidth(70));
    delay(SPEED); 
}

//gerak mundur_____sweep di bagian mundur
void mundur() {

}

/*............Gerakan menghindar partial alias patah2...........*/

//menghindar kanan
void hindar_kanan() {
  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(60));
  delay(d);
  //iki maju B
  pwm.setPWM(kakiB1, 0, pulseWidth(50)); //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(90));

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(60));
  delay(d);
  //iki maju
  pwm.setPWM(kakiD1, 0, pulseWidth(50)); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(90));

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(60));
//  delay(d);
//  //iki mundur
//  pwm.setPWM(kakiC1, 0, pulseWidth(80));
//  pwm.setPWM(kakiC2, 0, pulseWidth(60));
//
//  //sweep A
//  pwm.setPWM(kakiA2, 0, pulseWidth(35));
//  delay(d);
//  //iki mundur
//  pwm.setPWM(kakiA1, 0, pulseWidth(100));  //atas A
//  pwm.setPWM(kakiA2, 0, pulseWidth(60));

}

//menghindar kiri
void hindar_kiri() {
  //sweep A
  pwm.setPWM(kakiA2, 0, pulseWidth(35));
  delay(d);
  //iki mundur
  pwm.setPWM(kakiA1, 0, pulseWidth(100));//atas A
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(35));
  delay(d);
  //iki mundur
  pwm.setPWM(kakiC1, 0, pulseWidth(80));
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(35));
  delay(d);
  //iki maju
  pwm.setPWM(kakiD1, 0, pulseWidth(20)); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));

  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(35));
  delay(d);
  //iki maju B
  pwm.setPWM(kakiB1, 0, pulseWidth(30)); //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));
}

/*...............gerakan berbelok...............*/

//Belok Kanan
void kanan() {

  //sweep A
  pwm.setPWM(kakiA2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiA1, 0, pulseWidth(20)); //atasA
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiB1, 0, pulseWidth(20)); //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiC1, 0, pulseWidth(20)); //atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiD1, 0, pulseWidth(20)); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));


  //iki mundur A
  pwm.setPWM(kakiA1, 0, pulseWidth(100)); //atas A
  //iki mundur B
  pwm.setPWM(kakiB1, 0, pulseWidth(100));
  //mundur C
  pwm.setPWM(kakiC1, 0, pulseWidth(100));
  //iki mundur D
  delay(d);
  pwm.setPWM(kakiD1, 0, pulseWidth(100)); //atasD


}

//Belok Kiri
void kiri() {
  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiB1, 0, pulseWidth(100));//atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //sweep A
  pwm.setPWM(kakiA2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiA1, 0, pulseWidth(100));//atasA
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiD1, 0, pulseWidth(100)); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(30));
  delay(SPEED);
  //iki maju
  pwm.setPWM(kakiC1, 0, pulseWidth(100)); //atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //iki mundur B
  pwm.setPWM(kakiB1, 0, pulseWidth(40));
  //iki mundur A
  pwm.setPWM(kakiA1, 0, pulseWidth(40)); //atas A
  //iki mundur D
  pwm.setPWM(kakiD1, 0, pulseWidth(40)); //atasD
  //mundur C
  pwm.setPWM(kakiC1, 0, pulseWidth(40)); 

}

/*............Gerakan putar kanan kiri...........*/


void nol(){
  pwm.setPWM(kakiA1, 0, pulseWidth(90)); 
}
//jalan putar kanan
void putar_kanan() {
  kanan();
  kanan();
  kanan();
  kanan();
}

//jalan putar kiri
void putar_kiri() {
  kiri();
  kiri();
  kiri();
  kiri();
}


