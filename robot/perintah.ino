void algoritma(){
 sensor=analogRead(sound);
 buttonState=digitalRead(button);

//      if(sensor < 500)
//      {
//        if (buttonState == HIGH)
//        {
           if(cm0 <= 6)
              {
                hindar_kiri();
                tampil();
              }
            else if(cm4 <=10)
              {
                tampil();
                hindar_kanan();
                tampil();
                hindar_kanan();
              }
            else if(cm1 <= 20)
              {
                kanan();
                tampil();
                kanan();      
              }
            else if(cm3 <= 20)
              {
                kiri();
                tampil();
                kiri();
              }
              else if(cm2 <= 18)
              {
                tampil();
                mundur();  
              }
            else  
              {
                tampil();
                maju();
                 
              }

        //}
//     }
}
