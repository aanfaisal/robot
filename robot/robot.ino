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

int d = 150;                //delay sweep servo bawah

//ini sensor2 jarak ultrasonik
//sensorjarak kiri
int trig_pin = 15;
int echo_pin = 14;
//sensorjarak serong kiri
int trig_pin1 = 36;
int echo_pin1 = 37;
//sensorjarak tengah
int trig_pin2 = 30;
int echo_pin2 = 31;
//sensorjarak serong kanan
int trig_pin3 = 23;
int echo_pin3 = 22;
//sensorjarak kanan
int trig_pin4 = 10;
int echo_pin4 = 11;


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
int motor = 7;
int sepid = 200;

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
int api5 = 25;

//set kondisi default flame LOW
int kondisi1;
int kondisi2;
int kondisi3;
int kondisi4;
int kondisi5;

//ini lampu led merah
int led = 53;

//Ini variabel Sensor Garis
int garis1 = A4;
int garis2 = A5;
//line state sensor
int gris1 = 0;
int gris2 = 0;


//LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd(40, 41, 42, 43, 44, 45);


//Ini variabel sensor jarak
int pulse, cm0, pulse1, cm1, pulse2, cm2, pulse3, cm3, pulse4, cm4;
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

  pinMode(motor, OUTPUT);

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

  baca();

  algoritma();

//  //       api();
//
//    Serial.print("nomer 0 = ");
//    Serial.println(gris1);
//    Serial.print("nomer 1 = ");
//    Serial.println(gris2);
//    Serial.print("nomer 2 = ");
//    Serial.println(kondisi3);
//    Serial.print("nomer 3 = ");
//    Serial.println(kondisi4);
//    Serial.print("nomer 4 = ");
//    Serial.println(kondisi5);
  
//    delay(1000);

}
