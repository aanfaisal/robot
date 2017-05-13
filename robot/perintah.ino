void algoritma() {

  //        dengan begini robot akan mengikuti wall kanan
  //      standby1();
//  delay(200);

  while (sensor < 170 || buttonState == HIGH) {
    if (cm0 <= 6)           //kiri
    {
      hindar_kiri();
    }
    else if(cm4 <= 6)    // kanan
    {
      hindar_kanan();
    }
    //belok kiri
    else if((cm4<=12)&&(cm3<=14)&&(cm4<=12))
    {
      kiri();
      kiri();
      maju();
    }
    //kalo start dan dpane ada dinding
    else if((cm2<=15)&&(cm1<=8)&&(cm3<=8)) //ada halangan di depan kiri
    {
      kiri();
      kiri();
      maju();
    }
    else if((cm2 <= 9) && (cm3 <= 12)) //ada halangan di depan kanan
    {
      mundur();
      kanan();
      maju();
    }
    else if((cm4<=15)&&(cm0<=11)){
      kanan();
    }
    else if((gris1<=100)||(gris2<=100)){
        garis();
     }
    else if((kondisi1==0)&&(kondisi2==1)&&(kondisi3==1)&&(kondisi4==1)&&(kondisi5==0)){
        api();

    }
    else if(cm1 <= 14)    // serong kiri
    {
      kanan();
    }
    else if(cm3 <= 14)    //serong kanan
    {
      kiri();
    }

    else
    {
      maju();
      maju();
    }
  }
}
