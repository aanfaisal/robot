void api(){
  
 kondisi1=analogRead(flame1);
 kondisi2=analogRead(flame2);
 kondisi3=analogRead(flame3);
 kondisi4=analogRead(flame4);
 kondisi5=analogRead(flame5); 

    //deteksi api  
      if(kondisi1 >= 100 || kondisi2 >= 100 || kondisi3 >= 100 || kondisi4 >= 100 || kondisi5 >= 100)
      {
        Serial.println("Api Terdeteksi");
        Serial.println("LED dan Pompa Nyala");
        analogWrite(pompa, HIGH);
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
        analogWrite(pompa, LOW);
        delay(kondisi3);
      }

}

void garis(){
  gris1=analogRead(garis1);
  gris2=analogRead(garis2);
  gris3=analogRead(garis3);
  
}
