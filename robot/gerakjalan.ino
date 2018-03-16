void standby1() {
  //kaki bagian A standby
  pwm.setPWM(kakiA1, 0, pulseWidth(90));
  pwm.setPWM(kakiA2, 0, pulseWidth(90));
  //kaki bagian B standby
  pwm.setPWM(kakiB1, 0, pulseWidth(90));
  pwm.setPWM(kakiB2, 0, pulseWidth(90));
  //kaki bagian C standby
  pwm.setPWM(kakiC1, 0, pulseWidth(90));
  pwm.setPWM(kakiC2, 0, pulseWidth(90));
  //kaki bagian D standby
  pwm.setPWM(kakiD1, 0, pulseWidth(90));
  pwm.setPWM(kakiD2, 0, pulseWidth(90));
}

// kalo menemukan api
void standby2() {
  //sweep
  pwm.setPWM(kakiA2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiA1, 0, pulseWidth(60));//atasA
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiB2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiB1, 0, pulseWidth(60));  //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiC2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiC1, 0, pulseWidth(60));//atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiD2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiD1, 0, pulseWidth(60));  //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));
}


/*.............gerakan memulai berjalan..............*/
//gerak maju______sweep di bagian maju
void maju() {
 
}

//gerak mundur_____sweep di bagian mundur
void mundur() {

}

/*............Gerakan menghindar partial alias patah2...........*/

//menghindar kanan
void hindar_kanan() {
  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(35));
  delay(d);
  //iki maju B
  pwm.setPWM(kakiB1, 0, pulseWidth(30)); //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(35));
  delay(d);
  //iki maju
  pwm.setPWM(kakiD1, 0, pulseWidth(20)); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(35));
  delay(d);
  //iki mundur
  pwm.setPWM(kakiC1, 0, pulseWidth(80));
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep A
  pwm.setPWM(kakiA2, 0, pulseWidth(35));
  delay(d);
  //iki mundur
  pwm.setPWM(kakiA1, 0, pulseWidth(100));  //atas A
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

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


