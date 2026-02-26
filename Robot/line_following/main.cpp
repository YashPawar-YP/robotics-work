#include <bits/stdc++.h>

//right motor
#define AN1 21
#define AN2 22
#define PWMA 23

//left motor
#define BN1 17
#define BN2 16
#define PWMB 15

#define STBY 19 //used to enable/disable switch to control motor driver

const int base_speed = 150;


//pid
//pwm

//sensor pin
#define S0 7
#define S1 6
#define S2 9
#define S3 8
#define S4 12

void setup() {
    Serial.begin(115200);   
    
    //pin mode
    pinMode(AN1, OUTPUT);
    pinMode(AN2, OUTPUT);
    pinMode(BN1, OUTPUT);
    pinMode(BN2, OUTPUT);
    pinMode(STBY, OUTPUT);


    digitalWrite(STBY, HIGH); //enable motor driver












}