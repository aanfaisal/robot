#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal.h>

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
//ini motor
uint8_t motor = 8;
                  

// Ini variabel sound dan flame
const int sound = 7;

const int flame1 = A11;
const int flame2 = A12;
const int flame3 = A13; //flame tengah
const int flame4 = A14;
const int flame5 = A15;

//kondisi flame
int kondisi1 = 0;
int kondisi2 = 0;
int kondisi3 = 0;
int kondisi4 = 0;
int kondisi5 = 0;

//button
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
int pompa = A0;

//LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(40,41,42,43,44,45);

//Ini variabel sensor jarak
int pulse,cm0,pulse1,cm1,pulse2,cm2,pulse3,cm3,pulse4,cm4;
int i;
int sensor;


void setup() 
{
  Serial.begin(9600);
  

  //pinmode flame
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);

  //Ini pinmode untuk Sensor garis
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);

  //ini pinmode lampu LED
  pinMode(53, OUTPUT);
  
  //ini pinmode pompa
  pinMode(A0, OUTPUT);


  //pin modenya untuk sound
  pinMode(7, INPUT);

  //ini pinmode button
  pinMode(button, INPUT);
  
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
  lcd.print("9 BINTANG");

  lcd.begin(16, 2);
  lcd.setCursor(0,1); //baris bawah
  lcd.print("BISMILLAH");
  
  //Setting PWM  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  //setting sound
  sensor=digitalRead(sound);
  buttonState=digitalRead(button);


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
  
 algoritma();

}
