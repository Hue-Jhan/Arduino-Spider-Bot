#include <Servo.h>

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
float Dulation = 0;
float Distance = 0;
int angle = 90;
int sum = 0;

void setup(){
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
  delay(3000);
}

void loop(){
  standhome();
  forward(1);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  Dulation = pulseIn(echoPin,HIGH);

  if(Dulation>0){
    int Distance = Dulation*340*100/2/1000000;

    if(Distance < 10){
      int right = 0;
      int left = 0;
      int sumright = 0;
      int sumleft = 0;
      
      int i = 170;
      delay(10);
      while(i >= 120){
        neck_servo.write(i);
        i=i-2;
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        Dulation = pulseIn(echoPin,HIGH);
        int Distance = Dulation*340*100/2/1000000;
        
        if(Distance <15){
          left = 1;
          sumleft++;
        }else {
            left = 0;
          }
          delay(10);           
      }
      
     i =10;
     delay(10);
     while(i <= 60){
        neck_servo.write(i);
        i=i+2;
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        Dulation = pulseIn(echoPin,HIGH);
        int Distance = Dulation*340*100/2/1000000;

        if(Distance <15){
          right = 1;
          sumright++;
        }else {
          right = 0;
        }
          delay(10);       
     }


     neck_servo.write(90);
     delay(10);

      if(sumright > sumleft){
      leftturn(3);     
     } else {
      rightturn(3);
     }

     if(sumright >= 20){
      backward(3);
      leftturn(3);
     } else if(sumleft >= 20){
      backward(3);
      rightturn(3);
     }  
   }
}
delay(10);

}

void idle(){
  delay(100);
  }

void standhome(){
  joint2.write(home_joint2);
  joint3.write(home_joint3);
  joint4.write(home_joint4);
  joint5.write(home_joint5);
  joint6.write(home_joint6);
  joint7.write(home_joint7);
  joint8.write(home_joint8);
  joint9.write(home_joint9);
}

void sithome(){
    joint2.write(135);
    joint3.write(65);
    joint4.write(45);
    joint5.write(110);
    joint6.write(135);
    joint7.write(80);
    joint8.write(45);
    joint9.write(110);
}

void stand1(){
  sithome();
  joint2.write(170);
  delay(300);
  joint2.write(home_joint2);
  delay(300);
  joint4.write(10);
  delay(300);
  joint4.write(home_joint4);
  delay(300);
  joint6.write(170);
  delay(300);
  joint6.write(home_joint6);
  delay(300);
  joint8.write(10);
  delay(300);
  joint8.write(home_joint8);
  delay(300);
  joint3.write(home_joint3);
  joint5.write(home_joint5);
  joint7.write(home_joint7);
  joint9.write(home_joint9);
}

void stand2(){
  sithome();
  joint2.write(175);
  joint4.write(5);
  joint6.write(175);
  joint8.write(5);
  delay(600);
    
  joint2.write(home_joint2);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  joint8.write(home_joint8);
  delay(600);
  
  joint3.write(home_joint3);
  joint5.write(home_joint5);
  joint7.write(home_joint7);
  joint9.write(home_joint9);
}

void stand3(){ 
  sithome();
  int i;
  int j = 90;
  int k = 90;
  joint2.write(home_joint2);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  joint8.write(home_joint8);
  for(i = 90; i < 165; i++)
  {
    joint5.write(i);
    j = j - 1;
    joint3.write(j);
    delay(20);
  }
  
  for(i = 115; i < 165; i++)
  {
    joint9.write(i);
    k = k - 1;
    joint7.write(k);
    delay(20);
  }
}

void downaction(unsigned int step){
  while (step-- > 0){
  sithome();
  delay(100);
  standhome();
  delay(100);
  }
}

void wink(unsigned int step){
  standhome();
  joint9.write(home_joint9-30);
  while (step-- > 0){
  joint5.write(30);
  joint4.write(home_joint4 + 60);
  delay(300);
  joint4.write(home_joint4 - 60);
  delay(300);
  }
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
      delay(10);
  }

   for(int right=170;right>90;right--){
      joint2.write(right);
      joint6.write(right);
      joint4.write(right-90);
      joint8.write(right-90);
      delay(10);
  }

}

void forward(unsigned int step){
  while (step-- > 0){
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
  }
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
  neck_rightrotate();
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
  neck_home();
}

void leftturn(unsigned int step){
  neck_leftrotate();
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
  neck_home();
}

void neckrotate(){
  int i=90;
  while(i < 150){
    neck_servo.write(i);
    i++;
    delay(5);
  }
  while(i > 30){
    neck_servo.write(i);
    i--;
    delay(5);
  }
  while(i <= 90){
    neck_servo.write(i);
    i++;
    delay(5);
  }
}

void neck_leftrotate(){
  int i=90;
  while(i < 150){
    neck_servo.write(i);
    i++;
    delay(5);
  }
}

void neck_rightrotate(){
  int i=90;
  while(i > 30){
    neck_servo.write(i);
    i--;
    delay(5);
  }
}

void neck_home(){
  neck_servo.write(90);
}
