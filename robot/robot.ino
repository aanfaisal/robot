#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <NewPing.h>

//pin 20 adalah SDA
//pin 21 adalah SLC
//Ini servo driver (defaults address 0x40 di i2c nya kosongin ae)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH       500
#define MAX_PULSE_WIDTH       2500
#define DEFAULT_PULSE_WIDTH   1250
#define FREQUENCY             50
#define SPEED                 200
#define d                     500                //delay sweep servo bawah

/*---------------------------DEFINISI SRF-------------------------------------*/
#define SONAR_NUM     3 // banyaknya SRF-04 ultrasonik.
#define MAX_DISTANCE 200 // Maksimum deteksi (pd cm) buat nge ping.
#define PING_INTERVAL 33 // Milliseconds antara sensor pings (29ms minimalnya buat ngindari cross-sensor echo tabrakan).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.

NewPing sonar[SONAR_NUM] = {     // Array Sensor. NewPing(triggernya, echonya, maximum deteknya)
  NewPing(41, 42, MAX_DISTANCE), 
  NewPing(43, 44, MAX_DISTANCE),
  NewPing(45, 20, MAX_DISTANCE),
};
/*-----------------------------------------------------------------------------*/

/*------Definisi pin sensor kompass ( address 0x55 ) di i2c nya----------------*/
int kompas = 10;

/*--------------------Definisi Pin Kaki Servonya------------------------------*/
uint8_t kakiA1 = 0;
uint8_t kakiA2 = 1;
uint8_t kakiB1 = 12;
uint8_t kakiB2 = 13;
uint8_t kakiC1 = 14;
uint8_t kakiC2 = 15;
uint8_t kakiD1 = 4;
uint8_t kakiD2 = 5;

/*-----------------------Definisi Pin Pompa -----------------------------------*/
int motor = 7;
int sepid = 200;

/*-----------------------Definisi Pin Sound Sensor-----------------------------*/
int sound = A9;
int sensor = 0;

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

/*-----------------------Definisi Pin LED Kedip2-------------------------------*/
int led = 53;

//Ini variabel Sensor Garis 5 cenel
int garis1 = A14;
int garis2 = A13;
int garis3 = A12;
int garis4 = A11;
int garis5 = A10;

//line state sensor
int gris1 = 0;
int gris2 = 0;
int gris3 = 0;
int gris4 = 0;
int gris5 = 0;

/*------------------LiquidCrystal lcd(RS, E, D4, D5, D6, D7);-----------------*/
LiquidCrystal lcd(39, 40, 41, 42, 43, 44);

/*--------------------Ini variabel sensor jarak------------------------------*/
int pulse, cm0, pulse1, cm1, pulse2, cm2, pulse3, cm3, pulse4, cm4;
int i;
int F;
int disi[4];

/*---------------------ini variabel sensor sharp infrared jarak-------------*/
int pulsa0, cen0, pulsa1, cen1, pulsa2, cen2, pulsa3, cen3, pulsa4, cen4;
int s;
int T;
int sharp[5];

void setup()
{

  Serial.begin(9600);

  
/*------------Pinmode Flame Sensor---------------------------------------*/
  pinMode(api1, INPUT);
  pinMode(api2, INPUT);
  pinMode(api3, INPUT);
  pinMode(api4, INPUT);
  pinMode(api5, INPUT);

/*------------Pinmode Sound Sensor----------------------------------------*/
  pinMode(sound, INPUT);

/*------------Pinmode Sensor Garis----------------------------------------*/
  pinMode(garis1, INPUT);
  pinMode(garis2, INPUT);
  pinMode(garis3, INPUT);
  pinMode(garis4, INPUT);
  pinMode(garis5, INPUT);
/*------------Pinmode Lampu LED-------------------------------------------*/
  pinMode(led, OUTPUT);
/*------------Pinmode Pompa-----------------------------------------------*/
  pinMode(motor, OUTPUT);
  
/*--------------------------Buat Ngeping SRF-----------------------------------*/
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
/*-----------------------------------------------------------------------------*/

/*------------Nge Set LCD TU Begini-------------------------------------------*/
  lcd.begin(16, 2);
  lcd.setCursor(3, 0); //baris bawah
  lcd.print("BISMILLAH");
  
/*------------Setting PWM Servo-----------------------------------------------*/  //Setting PWM
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

}

/*------------Ini rumus mumet buat konversi pulse ke angle alias derajat------*/
int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide   = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  //Serial.println(analog_value);
  return analog_value;
}

/*------------Yang Di Looping--------------------------------------------------*/
void loop() {
    loopingan();
    standby1();//hindar_kanan();
}

