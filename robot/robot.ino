#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal.h>

//Ini servo driver (defaults to addr 0x40)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

#define MIN_PULSE_WIDTH       771
#define MAX_PULSE_WIDTH       3036
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50
#define SPEED                 300

  int d = 150; //delay servo bawah
  
  //ini sensor2 jarak ultrasonik
  //sensorjarak kiri
  int trig_pin=15;
  int echo_pin=14;
  //sensorjarak serong kiri
  int trig_pin1=36;
  int echo_pin1=37;
  //sensorjarak tengah
  int trig_pin2=30;
  int echo_pin2=31;
  //sensorjarak serong kanan
  int trig_pin3=23;
  int echo_pin3=22;
  //sensorjarak kanan
  int trig_pin4=10;
  int echo_pin4=11;
  
  
  //Servo 1~8
  // Kaki Servonya dikasih 
  uint8_t kakiA1 = 0;
  uint8_t kakiA2 = 1;
  uint8_t kakiB1 = 12;
  uint8_t kakiB2 = 13;
  uint8_t kakiC1 = 14;
  uint8_t kakiC2 = 15;
  uint8_t kakiD1 = 2;
  uint8_t kakiD2 = 3;
  
  //ini motor
  uint8_t motor = 8;
                    
  
  // Ini variabel sound dan flame
  const int sound = A15;

  
  boolean SensorState = false; 
  
  //sensor flame
  const int api1 = 11;
  const int api2 = 12;
  const int api3 = 13; //flame tengah
  const int api4 = 14;
  const int api5 = 15;
  
  //set kondisi default flame LOW
  int kondisi1 = 0;
  int kondisi2 = 0;
  int kondisi3 = 0;
  int kondisi4 = 0;
  int kondisi5 = 0;
  
  //button digital
  int button = 52;
  
  // variables will change:
  int buttonState = 0;         // variable for reading the pushbutton status

  //ini lampu led merah
  int led = 53;

  //Ini variabel Sensor Garis
  int garis1 = A4;
  int garis2 = A5;
  int garis3 = A6;
  
  int gris1=0;
  int gris2=0;
  int gris3=0;
  
  //Ini variabel Pompa Air
  //int pompa = A0;

    //LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
    LiquidCrystal lcd(40,41,42,43,44,45);

  //Ini variabel sensor jarak
  int pulse,cm0,pulse1,cm1,pulse2,cm2,pulse3,cm3,pulse4,cm4;
  int i;
  int sensor;
  int F;
  int disi[4];


void setup() 
{
  Serial.begin(9600);
  

  //pinmode flame
  pinMode(46, INPUT);
  pinMode(47, INPUT);
  pinMode(48, INPUT);
  pinMode(49, INPUT);
  pinMode(50, INPUT);

  //pin modenya untuk sound
  pinMode(A15, INPUT);

  //ini pinmode button
  pinMode(52, INPUT);
  
  //Ini pinmode untuk Sensor garis
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);

  //ini pinmode lampu LED
  pinMode(53, OUTPUT);
  
  //  ini pinmode pompa
  //  pinMode(A0, OUTPUT);

  
  //Ini pinmode untuk Sensor jarak
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin1, OUTPUT);
  pinMode(echo_pin1, INPUT);
  pinMode(trig_pin2, OUTPUT);
  pinMode(echo_pin2, INPUT);
  pinMode(trig_pin3, OUTPUT);
  pinMode(echo_pin3, INPUT);
  pinMode(trig_pin4, OUTPUT);
  pinMode(echo_pin4, INPUT);

  //Nge Set LCD tu begini
  lcd.begin(16, 2);
  lcd.setCursor(0,0); //baris atas
  lcd.print("BINTANG");

  lcd.begin(16, 2);
  lcd.setCursor(0,1); //baris bawah
  lcd.print("BISMILLAH");
  
  //Setting PWM  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  //setting sound
  sensor=analogRead(sound);
  
  //setting button
  buttonState=digitalRead(button);

  //setting api
   kondisi1=digitalRead(api1);
   kondisi2=digitalRead(api2);
   kondisi3=digitalRead(api3);
   kondisi4=digitalRead(api4);
   kondisi5=digitalRead(api5); 

  //setting garis
  gris1=analogRead(garis1);
  gris2=analogRead(garis2);
  gris3=analogRead(garis3);


}

//Ini rumus mumet buat konversi pulse ke angle alias derajat
int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}


void loop(){
  
//    if (analogRead(sound) >= 280 || buttonState == HIGH){
    
  //  delay(100);

//       if(cm0 <= 6)
//              {
//                hindar_kiri();
//              }
//            else if(cm4 <=10)
//              {
//                hindar_kanan();
//                hindar_kanan();
//              }
//            else if(cm1 <= 20)
//              {
//                kanan();
//                kanan();      
//              }
//            else if(cm3 <= 20)
//              {
//                kiri();
//                kiri();
//              }
//              else if(cm2 <= 18)
//              {
//                mundur();  
//              }
//            else  
//              {
//                maju();
//              }
//    }

//     if(analogRead(sound) >= 280 || buttonState==HIGH){algoritma();
//            if((kondisi1==HIGH)||(kondisi2==HIGH)||(kondisi3==HIGH)||(kondisi4==HIGH)||(kondisi5==HIGH)){api();
//                if((kondisi1==LOW)||(kondisi2==LOW)||(kondisi3==LOW)||(kondisi4==LOW)||(kondisi5==LOW)){algoritma();}}}
//                  if(gris1==HIGH||gris2==HIGH){standby1();
//                     if(gris1==LOW||gris2==LOW){algoritma();}}
//   algoritma();

      //program versi 3
        if(analogRead(sound) >= 280 || buttonState==HIGH)
        {F = 1;}
        else if(gris1>=500 && gris2>=500)
        {F = 2;}
        else if(gris1<=250 && gris2<=250)
        {F = 3;}
        else if()
        {F = 4;}
        else if((kondisi1==LOW)&&(kondisi2==LOW)&&(kondisi3==LOW)&&(kondisi4==LOW)&&(kondisi5==LOW))
        {F = 5;}
        else if((kondisi1==LOW)||(kondisi2==LOW)||(kondisi3==LOW)||(kondisi4==LOW)||(kondisi5==LOW))
        {F = 6;}
        else
        {F = 0;}
        
        switch (F)
        { case 1 : label : digitalWrite(7, LOW);
                   digitalWrite(2, HIGH);
                   if(digitalRead(api5) == 1)
                   {digitalWrite(2,LOW);
                   break;}
                   else if(digitalRead(api5) == 1)
                   {digitalWrite(2,LOW);
                   break;}
                   else if(digitalRead(api4) == 1)
                   {break;}
                   else
                   {goto label;}
          break;
          case 2 : label2 : digitalWrite(7, LOW);
                   digitalWrite(3, HIGH);
                   if (digitalRead(api1) == 1)
                   {digitalWrite(3,LOW);
                   break;}
                   else if(digitalRead(api3) == 1)
                   {digitalWrite(3,LOW);
                   break;}
                   else if(digitalRead(api4) == 1)
                   {break;}
                   else
                   {goto label2;}
          break;
          case 3 : label3 : digitalWrite(7, LOW);
                   digitalWrite(4, HIGH);
                   if(digitalRead(api2) == 1)
                   {digitalWrite(4,LOW);
                   break;}
                   else if(digitalRead(api4) == 1)
                   {digitalWrite(4,LOW);
                   break;}
                   else if(digitalRead(api4) == 1)
                   {break;}
                   else
                   {goto label3;}
          break;
          case 4 : label5 :digitalWrite(7, LOW);
                   digitalWrite(5, HIGH);
                   if(digitalRead(api3) == 1)
                   {digitalWrite(5,LOW);
                   break;}
                   else if(digitalRead(api5) == 1)
                   {digitalWrite(5,LOW);
                   break;}
                   else if(digitalRead(api4) == 1)
                   {break;}
                   else
                   {goto label5;}
          break;
          case 5 : label6: digitalWrite(7, LOW);
                   digitalWrite(6, HIGH);
                   if(digitalRead(api4) == 1)
                   {digitalWrite(6,LOW);
                   break;}
                   else if(digitalRead(api4) == 1)
                   {break;}
                   else if(digitalRead(api1) == 1)
                   {digitalWrite(6,LOW);
                   goto label;}
                   else
                   {goto label6;}
          break;
          case 6 :  digitalWrite(7, HIGH);
                    digitalWrite(2, LOW);
                    digitalWrite(3, LOW);
                    digitalWrite(4, LOW);
                    digitalWrite(5, LOW);
                    digitalWrite(6, LOW);
         break;
          
         default :  digitalWrite(7, HIGH);
                    digitalWrite(2, LOW);
                    digitalWrite(3, LOW);
                    digitalWrite(4, LOW);
                    digitalWrite(5, LOW);
                    digitalWrite(6, LOW);
          break;
      }
}
