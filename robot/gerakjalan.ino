void standby1(){
  //kaki bagian A standby
  pwm.setPWM(kakiA1, 0, pulseWidth(60));
  pwm.setPWM(kakiA2, 0, pulseWidth(60));
  //kaki bagian B standby
  pwm.setPWM(kakiB1, 0, pulseWidth(60));
  pwm.setPWM(kakiB2, 0, pulseWidth(60));
  //kaki bagian C standby
  pwm.setPWM(kakiC1, 0, pulseWidth(60));
  pwm.setPWM(kakiC2, 0, pulseWidth(60));
  //kaki bagian D standby
  pwm.setPWM(kakiD1, 0, pulseWidth(60));
  pwm.setPWM(kakiD2, 0, pulseWidth(60));
}

// kalo menemukan api
void standby2(){
  //sweep
  pwm.setPWM(kakiA2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiA1, 0, pulseWidth(60));//atasA
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiB2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiB1, 0, pulseWidth(60)); tampil(); //atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiC2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiC1, 0, pulseWidth(60));//atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep
  pwm.setPWM(kakiD2, 0, pulseWidth(40));
  delay(d);
  pwm.setPWM(kakiD1, 0, pulseWidth(60)); tampil(); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));
}


/*.............gerakan memulai berjalan..............*/
//gerak maju______sweep di bagian maju
void maju(){
  //iki mundur
  pwm.setPWM(kakiA1, 0, pulseWidth(100)); tampil();

  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(38));
  delay(d);
  //iki maju B
  pwm.setPWM(kakiB1, 0, pulseWidth(80)); tampil();//atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(62));

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(38));
  delay(d);
  delay(d);
  //iki maju
  pwm.setPWM(kakiD1, 0, pulseWidth(40)); //atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));

  //iki mundur
  pwm.setPWM(kakiC1, 0, pulseWidth(40)); tampil();

  //...............batas suci........................//
  //iki mundur
  pwm.setPWM(kakiB1, 0, pulseWidth(22)); tampil();

  //sweep A
  pwm.setPWM(kakiA2, 0, pulseWidth(38));
  delay(d);
  //iki maju
  pwm.setPWM(kakiA1, 0, pulseWidth(40)); tampil();//atasA
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(38));
  delay(d);
  //iki maju
  pwm.setPWM(kakiC1, 0, pulseWidth(80)); tampil();//atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));
  //iki mundur
  pwm.setPWM(kakiD1, 0, pulseWidth(80)); tampil();

}

//gerak mundur_____sweep di bagian mundur
void mundur(){
  //iki maju
  pwm.setPWM(kakiC1, 0, pulseWidth(80)); //atasC

  //sweep D
  pwm.setPWM(kakiD2, 0, pulseWidth(45));
  delay(d);
  //iki mundur
  pwm.setPWM(kakiD1, 0, pulseWidth(80));
  pwm.setPWM(kakiD2, 0, pulseWidth(60));

  //sweep B
  pwm.setPWM(kakiB2, 0, pulseWidth(45));
  delay(d);
  //iki mundur
  pwm.setPWM(kakiB1, 0, pulseWidth(40));
  pwm.setPWM(kakiB2, 0, pulseWidth(60));

  //iki maju
  pwm.setPWM(kakiA1, 0, pulseWidth(40)); tampil();//atasA

  //...............batas suci........................//
  //iki maju D
  pwm.setPWM(kakiD1, 0, pulseWidth(40)); //atasD

  //sweep C
  pwm.setPWM(kakiC2, 0, pulseWidth(45));
  delay(d);
  //iki mundur C
  pwm.setPWM(kakiC1, 0, pulseWidth(40));
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //sweep A
  pwm.setPWM(kakiA2, 0, pulseWidth(45));
  delay(d);
  //iki mundur A
  pwm.setPWM(kakiA1, 0, pulseWidth(80));
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

  //iki maju B
  pwm.setPWM(kakiB1, 0, pulseWidth(80)); tampil();//atasB

}


/*............Gerakan menghindar partial alias patah2...........*/

//menghindar kanan
void hindar_kanan(){
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
  pwm.setPWM(kakiA1, 0, pulseWidth(100)); tampil(); //atas A
  pwm.setPWM(kakiA2, 0, pulseWidth(60));

}

//menghindar kiri
void hindar_kiri(){
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
  pwm.setPWM(kakiB1, 0, pulseWidth(30)); tampil();//atasB
  pwm.setPWM(kakiB2, 0, pulseWidth(60));
}

/*...............gerakan berbelok...............*/

//Belok Kanan
void kanan(){

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
  pwm.setPWM(kakiD1, 0, pulseWidth(20)); tampil();//atasD
  pwm.setPWM(kakiD2, 0, pulseWidth(60));
  
 
  //iki mundur A
  pwm.setPWM(kakiA1, 0, pulseWidth(100)); //atas A
  //iki mundur B
  pwm.setPWM(kakiB1, 0, pulseWidth(100));
  //mundur C
  pwm.setPWM(kakiC1, 0, pulseWidth(100));
  //iki mundur D
  delay(d);
  pwm.setPWM(kakiD1, 0, pulseWidth(100)); tampil();//atasD
  
 
}

//Belok Kiri
void kiri(){
  

  
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
  pwm.setPWM(kakiC1, 0, pulseWidth(100)); tampil();//atasC
  pwm.setPWM(kakiC2, 0, pulseWidth(60));

  //iki mundur B
  pwm.setPWM(kakiB1, 0, pulseWidth(40));
  //iki mundur A
  pwm.setPWM(kakiA1, 0, pulseWidth(40)); //atas A
  //iki mundur D
  pwm.setPWM(kakiD1, 0, pulseWidth(40)); //atasD
  //mundur C
  pwm.setPWM(kakiC1, 0, pulseWidth(40)); tampil();
  
}

/*............Gerakan putar kanan kiri...........*/

//jalan putar kanan
void putar_kanan(){
  kanan();
  kanan();
  kanan();
  kanan();
}

//jalan putar kiri
void putar_kiri(){
  kiri();
  kiri();
  kiri();
  kiri();
}


