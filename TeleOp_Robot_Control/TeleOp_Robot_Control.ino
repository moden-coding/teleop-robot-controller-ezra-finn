#include "WebHelper.h"  //Keep, do not MODIFY!
#include <ESP32Servo.h>
Servo servo;
int servopin = 20;
int Right_FrontA = 10;
int Right_FrontB = 6;
int Left_FrontA = 8;
int Left_FrontB = 4;
int Right_BackA = 7;
int Right_BackB = 11;
int Left_BackA = 5;
int Left_BackB = 9;

void setup() {
  Serial.begin(9600);
  setupOTA();
  setupWebServer();
  pinMode(Right_FrontA, OUTPUT);
  pinMode(Right_FrontB, OUTPUT);
  pinMode(Left_FrontA, OUTPUT);
  pinMode(Left_FrontB, OUTPUT);
  pinMode(Right_BackA, OUTPUT);
  pinMode(Right_BackB, OUTPUT);
  pinMode(Left_BackA, OUTPUT);
  pinMode(Left_BackB, OUTPUT);
  servo.attach(servopin);
}

void loop() {  // put your main code here, to run repeatedly:
  handleWebServer();
  servo.write(90);
  if(keyboard.i){
    servo.write(20);
    delay(500);
    servo.write(90);
    delay(1000);
  }else if(keyboard.w && keyboard.a){
rightfrontDrive(1);
  leftfrontDrive(0);
  rightbackDrive(0);
  leftbackDrive(1);
}else if(keyboard.w && keyboard.d){
rightfrontDrive(0);
  leftfrontDrive(1);
  rightbackDrive(1);
  leftbackDrive(0);
   }else if(keyboard.s && keyboard.a){
rightfrontDrive(0);
  leftfrontDrive(-1);
  rightbackDrive(-1);
  leftbackDrive(0);
  }else if(keyboard.s && keyboard.d){
rightfrontDrive(-1);
  leftfrontDrive(0);
  rightbackDrive(0);
  leftbackDrive(-1);
  }else if(keyboard.w){
rightfrontDrive(1);
  leftfrontDrive(1);
  rightbackDrive(1);
  leftbackDrive(1);
}else if(keyboard.a){
rightfrontDrive(1);
  leftfrontDrive(-1);
  rightbackDrive(-1);
  leftbackDrive(1);
}else if(keyboard.d){
rightfrontDrive(-1);
  leftfrontDrive(1);
  rightbackDrive(1);
  leftbackDrive(-1);
}else if(keyboard.s){
rightfrontDrive(-1);
  leftfrontDrive(-1);
  rightbackDrive(-1);
  leftbackDrive(-1);
  }else if(keyboard.q){
rightfrontDrive(1);
  leftfrontDrive(-1);
  rightbackDrive(1);
  leftbackDrive(-1);
  }else if(keyboard.e){
rightfrontDrive(-1);
  leftfrontDrive(1);
  rightbackDrive(-1);
  leftbackDrive(1);
  }else{
rightfrontDrive(0);
  leftfrontDrive(0);
  rightbackDrive(0);
  leftbackDrive(0);

  }


}  //Keep, do not MODIFY!
void rightfrontDrive(double power) {
  float setPower = map(power * 100, -100, 100, 0, 255);
  analogWrite(Right_FrontA, setPower);
  analogWrite(Right_FrontB, 255 - setPower);
}

void leftfrontDrive(double power) {
  float setPower = map(power * 100, -100, 100, 0, 255);
  analogWrite(Left_FrontA, setPower);
  analogWrite(Left_FrontB, 255 - setPower);
}
void rightbackDrive(double power) {
  float setPower = map(power * 100, -100, 100, 0, 255);
  analogWrite(Right_BackA, setPower);
  analogWrite(Right_BackB, 255 - setPower);
}

void leftbackDrive(double power) {
  float setPower = map(power * 100, -100, 100, 0, 255);
  analogWrite(Left_BackA, setPower);
  analogWrite(Left_BackB, 255 - setPower);
}
