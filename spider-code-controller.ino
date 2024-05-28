#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial hc05(0, 1);

Servo joint2;
Servo joint3;
Servo joint4;  
Servo joint5;  
Servo joint6;  
Servo joint7;  
Servo joint8;  
Servo joint9;  
Servo neck_servo;  
int home_joint2 = 120;
int home_joint3 = 15;
int home_joint4 = 60;
int home_joint5 = 165;
int home_joint6 = 100;
int home_joint7 = 15;
int home_joint8 = 70;
int home_joint9 = 165;
#define neck_survoPin 10
#define trigPin 11
#define echoPin 12
float Dulation, Distance, sum = 0;
int angle = 90;

void setup(){
  Serial.begin(9600);
  Serial.println("Enter comand: ");
  hc05.begin(9600);
  delay(1000);

  joint2.attach(2);
  joint3.attach(3);
  joint4.attach(4);
  joint5.attach(5);
  joint6.attach(6);
  joint7.attach(7);
  joint8.attach(8);
  joint9.attach(9);
  neck_servo.attach(neck_survoPin, 500, 2400);
  neck_servo.write(90);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  joint2.write(home_joint2);
  joint3.write(home_joint3);
  joint4.write(home_joint4);
  joint5.write(home_joint5);
  joint6.write(home_joint6);
  joint7.write(home_joint7);
  joint8.write(home_joint8);
  joint9.write(home_joint9);
  // standhome();
  // sithome();
  delay(1000);  }

bool moving = false;

void loop() {
  unsigned long currentTime = millis();
  if (hc05.available() > 0) {
    char data = hc05.read();
    execute(data);
    Serial.print(data);
  }
}

void execute(char data) {
  switch (data) {
    case 'F':
      forward(2);
      break;
    case 'v':
      Serial.println("bals xdd");
      break;
    case 'B':
      backward(2);
      break;
    case 'R':
      rightturn(2);
      break;
    case 'L':
      leftturn(2);
      break;
    case 'T':
      wink(2);
      break;
    case 'S':
      sithome();
      break;
    case 'C':
      twist();
      break;
    case 'X':
      stand1();
      break;
    default:
      Serial.println("error xd");
      break;
  }
}
  /* if (Serial.available() > 0) {
    char data = Serial.read();
    Serial.print(data);
    if (data == 'F') { 
      forward(2);  }
    else if (data == 'v') {
      Serial.println("bals xdd"); }
    else if (data == 'B') {
      backward(2); }
  }   */

void sithome(){
    joint2.write(135);
    delay(200);
    joint3.write(65);
    delay(200);
    joint4.write(45);
    delay(200);
    joint5.write(110);
    delay(200);
    joint6.write(135);
    delay(200);
    joint7.write(80);
    delay(200);
    joint8.write(45);
    delay(200);
    joint9.write(110);
    delay(200); }

void idle(){
  delay(100); }

void standhome(){
  joint2.write(home_joint2);
  delay(200);
  joint3.write(home_joint3);
  delay(200);
  joint4.write(home_joint4);
  delay(200);
  joint5.write(home_joint5);
  delay(200);
  joint6.write(home_joint6);
  delay(200);
  joint7.write(home_joint7);
  delay(200);
  joint8.write(home_joint8);
  delay(200);
  joint9.write(home_joint9);
  delay(200); }

void stand1(){
  sithome();
  joint2.write(170);
  delay(400);
  joint2.write(home_joint2);
  delay(400);
  joint4.write(10);
  delay(400);
  joint4.write(home_joint4);
  delay(400);
  joint6.write(170);
  delay(400);
  joint6.write(home_joint6);
  delay(400);
  joint8.write(10);
  delay(400);
  joint8.write(home_joint8);
  delay(400);
  joint3.write(home_joint3);
  delay(200);
  joint5.write(home_joint5);
  delay(200);
  joint7.write(home_joint7);
  delay(200);
  joint9.write(home_joint9);
  delay(200); }

void neckrotate(){
  int i=90;
  while(i < 150){
    neck_servo.write(i);
    i++;
    delay(5); }
  while(i > 30){
    neck_servo.write(i);
    i--;
    delay(5); }
  while(i <= 90){
    neck_servo.write(i);
    i++;
    delay(5); }
}

void forward(unsigned int step){
 // while (isPressed) {
 //  while (step-- >= 0){
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  // } }
}

void backward(unsigned int step){
  while (step-- > 0){
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  }
}

void rightturn(unsigned int step){
  while (step-- > 0){
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  }
}

void leftturn(unsigned int step){
  while (step-- > 0){
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  }
}

void neck_leftrotate(){
  int i=90;
  while(i < 150){
    neck_servo.write(i);
    i++;
    delay(5); } }
void neck_rightrotate(){
  int i=90;
  while(i > 30){
    neck_servo.write(i);
    i--;
    delay(5);  }  }
void neck_home(){
  neck_servo.write(90);
}

void twist(){
  joint3.write(home_joint3);
  joint5.write(home_joint5);
  joint7.write(home_joint7);
  joint9.write(home_joint9);
  for(int right=90;right<170;right++){
      joint2.write(right);
      joint6.write(right);
      joint4.write(right-90);
      joint8.write(right-90);
      delay(10);  }
   for(int right=170;right>90;right--){
      joint2.write(right);
      joint6.write(right);
      joint4.write(right-90);
      joint8.write(right-90);
      delay(10);  }
}

void wink(unsigned int step){
  standhome();
  joint9.write(home_joint9-30); 
  while (step-- > 0){
  joint5.write(30);
  joint4.write(home_joint4 + 60);
  delay(300);
  joint4.write(home_joint4 - 60);
  delay(300);  }
}
