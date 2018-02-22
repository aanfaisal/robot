#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <NewPing.h>

//pin 21 adalah SDA
//pin 22 adalah SLC
//Ini servo driver (defaults address 0x40 di i2c nya kosongin ae)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       500
#define MAX_PULSE_WIDTH       2500
#define DEFAULT_PULSE_WIDTH   1250
#define FREQUENCY             50
#define SPEED                 2000

/*---------------------------DEFINISI SRF-------------------------------------*/
#define SONAR_NUM     5 // banyaknya SRF-04 ultrasonik.
#define MAX_DISTANCE 200 // Maksimum deteksi (in cm) buat nge ping.
#define PING_INTERVAL 33 // Milliseconds antara sensor pings (29ms minimalnya buat ngindari cross-sensor echo tabrakan).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.

NewPing sonar[SONAR_NUM] = {     // Array Sensor. NewPing(triggernya, echonya, maximum deteknya)
  NewPing(41, 42, MAX_DISTANCE), 
  NewPing(43, 44, MAX_DISTANCE),
  NewPing(45, 20, MAX_DISTANCE),
  NewPing(21, 22, MAX_DISTANCE),
  NewPing(23, 24, MAX_DISTANCE),
};
/*-----------------------------------------------------------------------------*/

int d = 500;                //delay sweep servo bawah

/*------Definisi pin sensor kompass ( address 0x55 ) di i2c nya----------------*/
int kompas = 10;
/*-----------------------------------------------------------------------------*/

////ini sensor2 jarak ultrasonik
////sensorjarak 1
//int trig_pin = 15;
//int echo_pin = 14;
////sensorjarak 2
//int trig_pin1 = 36;
//int echo_pin1 = 37;
////sensorjarak 3
//int trig_pin2 = 30;
//int echo_pin2 = 31;
////sensorjarak 4
//int trig_pin3 = 23;
//int echo_pin3 = 22;
////sensorjarak 5
//int trig_pin4 = 10;
//int echo_pin4 = 11;

/*--------------------Definisi Pin Kaki Servonya------------------------------*/
uint8_t kakiA1 = 0;
uint8_t kakiA2 = 1;
uint8_t kakiB1 = 14;
uint8_t kakiB2 = 15;
uint8_t kakiC1 = 12;
uint8_t kakiC2 = 13;
uint8_t kakiD1 = 2;
uint8_t kakiD2 = 3;
/*-----------------------------------------------------------------------------*/

/*-----------------------Definisi Pin Pompa -----------------------------------*/
int motor = 7;
int sepid = 200;
/*-----------------------------------------------------------------------------*/

/*-----------------------Definisi Pin Sound Sensor-----------------------------*/
int sound = A9;
int sensor = 0;
/*-----------------------------------------------------------------------------*/

/*----------------------Definisi Button ON-------------------------------------*/
int button = 52;

//variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
/*-----------------------------------------------------------------------------*/

/*----------------------Definisi Pin Sensor Api--------------------------------*/
int api1 = 46;
int api2 = 47;
int api3 = 48; //flame tengah
int api4 = 49;
int api5 = 25;

//set kondisi default flame LOW
int kondisi1;
int kondisi2;
int kondisi3;
int kondisi4;
int kondisi5;
/*-----------------------------------------------------------------------------*/

/*-----------------------Definisi Pin LED Kedip2-------------------------------*/
int led = 53;

//Ini variabel Sensor Garis 5 cenel
int garis1 = A4;
int garis2 = A5;
int garis3 = A6;
int garis4 = A7;
int garis5 = A8;

//line state sensor
int gris1 = 0;
int gris2 = 0;
int gris3 = 0;
int gris4 = 0;
int gris5 = 0;

/*------------------LiquidCrystal lcd(RS, E, D4, D5, D6, D7);-----------------*/
LiquidCrystal lcd(40, 41, 42, 43, 44, 45);
/*----------------------------------------------------------------------------*/

//Ini variabel sensor jarak
int pulse, cm0, pulse1, cm1, pulse2, cm2, pulse3, cm3, pulse4, cm4;
int i;
int F;
int disi[4];

//ini variabel sensor sharp infrared jarak
int pulsa0, cen0, pulsa1, cen1, pulsa2, cen2, pulsa3, cen3, pulsa4, cen4;
int s;
int T;
int sharp[5];

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

  pinMode(motor, OUTPUT);
  
/*--------------------------Buat Ngeping SRF-------------------------------*/
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
/*-----------------------------------------------------------------------------*/

//  //Ini pinmode untuk Sensor jarak
//  pinMode(trig_pin, OUTPUT);
//  pinMode(echo_pin, INPUT);
//  pinMode(trig_pin1, OUTPUT);
//  pinMode(echo_pin1, INPUT);
//  pinMode(trig_pin2, OUTPUT);
//  pinMode(echo_pin2, INPUT);
//  pinMode(trig_pin3, OUTPUT);
//  pinMode(echo_pin3, INPUT);
//  pinMode(trig_pin4, OUTPUT);
//  pinMode(echo_pin4, INPUT);

  //Nge Set LCD tu begini
  lcd.begin(16, 2);
  lcd.setCursor(3, 0); //baris bawah
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

void loop() {
    tampil();
    baca();
    standby1();
}

