void algoritma(){

//        dengan begini robot akan mengikuti wall kanan
//
        if(cm0 <= 6)
            {
              hindar_kiri();
            }
          else if(cm4 <=10)
            {
              hindar_kanan();
              hindar_kanan();
            }
          else if(cm1 <= 20)
            {
              kanan();
              kanan();      
            }
          else if(cm3 <= 20)
            {
              kiri();
              kiri();
            }
            else if(cm2 <= 18)
            {
              mundur();  
            }
          else  
            {
              maju();
            }
}
