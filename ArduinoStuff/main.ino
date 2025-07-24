#include <Servo.h>

#define SERVO_PIN_1 25; // tbd
#define SERVO_PIN_2 26; // also tbd

Servo s1; 
Servo s2; 

enum state_enum{SEARCH, LEFT, RIGHT, CENTER, UP, DOWN};
int state = SEARCH;

void setup() {
  // put your setup code here, to run once:
  s1.attach(7);
  s2.attach(10);
  s1.writeMicroseconds(1000);
  s2.writeMicroseconds(1000);
  Serial.begin(9600);
}

int currPosX = 1500; 
int currPosY = 1500;

//TODO: Figure out constraints

int angleConstrain(int currentAngle){
  if(currentAngle > 2000){
    return 2000;
  }else if(currentAngle < 1000){
    return 1000;
  }
  return currentAngle;
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("PRINTING"); 
  if(Serial.available() > 0){
    Serial.println("RECEIVED TARGET");
    String input = Serial.readString();
    input.trim();
    
    if(input.equals("LEFT")){
      state = LEFT; 
    }else if(input.equals("RIGHT")){
      state = RIGHT;
    }else if(input.equals("CENTER")){
      state = CENTER;
    }else if(input.equals("UP")){
      state = UP;
    }else if(input.equals("DOWN")){
      state = DOWN;
    }


    switch(state){
      case LEFT:
        currPosX -= 50;
        s1.writeMicroseconds(angleConstrain(currPosX));
        Serial.println("AIMING LEFT");
        Serial.println("X: " + currPosX + "\nY: " + currPosY);
        break;
      case RIGHT:
        currPosX += 50;
        s1.writeMicroseconds(angleConstrain(currPosX));
        Serial.println("AIMING RIGHT");
        Serial.println("X: " + currPosX + "\nY: " + currPosY);
        break;
      case UP:
         currPosY += 50;
         s2.writeMicroseconds(angleConstrain(currPosY));
         Serial.println("AIMING UP");
         Serial.println("X: " + currPosX + "\nY: " + currPosY);
         break;
      case DOWN: 
        currPosY -= 50;  
        s2.writeMicroseconds(angleConstrain(currPosY));
        Serial.println("AIMING DOWN");
        Serial.println("X: " + currPosX + "\nY: " + currPosY);
      case CENTER:
        Serial.println("TARGET CENTERED");
        Serial.println("X: " + currPosX + "\nY: " + currPosY);
        break;
      default: 
        break;
    }
  }
}