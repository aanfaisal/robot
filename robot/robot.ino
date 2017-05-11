#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal.h>
//#include <SoftwareSerial.h>

//Ini servo driver (defaults to addr 0x41)
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

//ini motor pompa
int motor = 8;
                  
  
// Ini variabel sound dan flame
int sound = A7;
int sensor = 0;

//button digital
int button = 52;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
  
//sensor flame
 int api1 = 46;
 int api2 = 47;
 int api3 = 48; //flame tengah
 int api4 = 49;
 int api5 = 50;

//set kondisi default flame LOW
int kondisi1 = 0;
int kondisi2 = 0;
int kondisi3 = 0;
int kondisi4 = 0;
int kondisi5 = 0;


//ini lampu led merah
int led = 53;

//Ini variabel Sensor Garis
int garis1 = A4;
int garis2 = A5;
//line state sensor
int gris1=0;
int gris2=0;

//Ini variabel Pompa Air
//int pompa = A0;

//LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(40,41,42,43,44,45);


//Ini variabel sensor jarak
int pulse,cm0,pulse1,cm1,pulse2,cm2,pulse3,cm3,pulse4,cm4;
int i;
int F;
int disi[4];


void setup() 
{

  Serial.begin(9600);
  
  //pinmode flame
  pinMode(api1, INPUT);
  pinMode(api2, INPUT);
  pinMode(api3, INPUT);
  pinMode(api4, INPUT);
  pinMode(api5, INPUT);

  //pin modenya untuk sound
  pinMode(sound, INPUT);

  //ini pinmode button
  pinMode(button, INPUT);
  
  //Ini pinmode untuk Sensor garis
  pinMode(garis1, INPUT);
  pinMode(garis2, INPUT);

  //ini pinmode lampu LED
  pinMode(led, OUTPUT);
  
  
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
  lcd.setCursor(3,0); //baris bawah
  lcd.print("BISMILLAH");

  //lcd.begin(16, 2);
  //lcd.setCursor(0,0); //baris atas
  //lcd.print("BINTANG");
  
  //Setting PWM  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

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
    
       baca();
      
         Serial.print("nomer 0 = ");
         Serial.println(kondisi1);
         Serial.print("nomer 1 = ");
         Serial.println(kondisi2);
         Serial.print("nomer 2 = ");
         Serial.println(kondisi3);
         Serial.print("nomer 3 = ");
         Serial.println(kondisi4);
         Serial.print("nomer 4 = ");
         Serial.println(kondisi5);

         delay(1000);

////    
//     if(sensor < 200 || buttonState==HIGH){
//         algoritma();
//     }
//     else if(gris1>=500 && gris2>=500){
//          algoritma();
//     }
//     else if(gris1<=250 && gris2<=250){
//          standby1();
//     }
//     else if((kondisi1==LOW)&&(kondisi2==LOW)&&(kondisi3==LOW)&&(kondisi4==LOW)&&(kondisi5==HIGH)){
//          algoritma();
//     }
//     else if((kondisi1==LOW)&&(kondisi2==HIGH)&&(kondisi3==HIGH)&&(kondisi4==HIGH)&&(kondisi5==LOW)){
//          delay(100);
//          api();
//     }
//    else{
//        standby1();
//    }
//      
//     if((kondisi1==HIGH)||(kondisi2==HIGH)||(kondisi3==HIGH)||(kondisi4==HIGH)||(kondisi5==HIGH)){api();
//                if((kondisi1==LOW)||(kondisi2==LOW)||(kondisi3==LOW)||(kondisi4==LOW)||(kondisi5==LOW)){algoritma();}}}
//                  if(gris1==HIGH||gris2==HIGH){standby1();
//                     if(gris1==LOW||gris2==LOW){algoritma();}}
//      algoritma();
//
//
//      //program versi 3
//        if(sensor < 380)
//        {F = 1;}
//        else if(buttonState==HIGH)
//        {F = 2;}
//        else if(gris1>=500 && gris2>=500)
//        {F = 3;}
//        else if(gris1<=250 && gris2<=250)
//        {F = 4;}
//        else if((kondisi1==LOW)&&(kondisi2==LOW)&&(kondisi3==LOW)&&(kondisi4==LOW)&&(kondisi5==LOW))
//        {F = 5;}
//        else if((kondisi1==LOW)||(kondisi2==HIGH)||(kondisi3==HIGH)||(kondisi4==HIGH)||(kondisi5==LOW))
//        {F = 6;}
//        else
//        {F = 0;}
//        
//        switch (F)
//        { 
//          case 1 : label : 
//                          algoritma();
//                   {goto label;}         
//          break;
//          
//          case 2 : label2 : algoritma();
//                   
//                   {goto label2;}
//          break;
//          
//          case 3 : label3 : 
//                   if(gris1>=500 && gris2>=500)
//                   {algoritma();
//                   break;}
//                   else if(gris1<=250 && gris2<=250)
//                   {delay(50);algoritma();
//                   break;}
//                   else
//                   {goto label3;}
//          break;
//          
//          case 4 : label5 :
//                   if(gris1<=250 && gris2<=250)
//                   {maju();delay(100);
//                   break;}
//                   else if(gris1>=500 && gris2>=500)
//                   {delay(10);algoritma();
//                   break;}
//                   else
//                   {goto label5;}
//          break;
//          
//          case 5 : label6: delay(10);algoritma();
//          
//                   {goto label6;}
//          break;
//          case 6 :  label7: delay(10);
//                    api();
//                   {goto label7;}
//          break;
//            
//          default :  standby1();
//          break;
//      }
}
