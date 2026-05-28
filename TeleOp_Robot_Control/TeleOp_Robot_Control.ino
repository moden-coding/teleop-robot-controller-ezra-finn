#include "WebHelper.h"  //Keep, do not MODIFY!

int Right_FrontA = 10 
int Right_FrontB = 7 
int Left_FrontA = 4 
int Left_FrontB = 8 
int Right_BackA = 6 
int Right_BackB = 11 
int Left_BackA = 9 
int Left_BackB = 5

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
}

void loop() {         // put your main code here, to run repeatedly:
  handleWebServer();  //Keep, do not MODIFY!
  void leftDrive(double power) {
float setPower = map(power * 100, -100, 100, 0, 255);
analogWrite(Right_FrontA, setPower);
analogWrite(Right_FrontB, 255 - setPower);
}

void rightDrive(double power) {
float setPower = map(power * 100, -100, 100, 0, 255);
analogWrite(Left_FrontA, setPower);
analogWrite(Left_FrontB, 255 - setPower);

void leftDrive(double power) {
float setPower = map(power * 100, -100, 100, 0, 255);
analogWrite(Right_BackA, setPower);
analogWrite(Right_BackB, 255 - setPower);
}

void rightDrive(double power) {
float setPower = map(power * 100, -100, 100, 0, 255);
analogWrite(Left_BackA, setPower);
analogWrite(Left_BackB, 255 - setPower);
}

