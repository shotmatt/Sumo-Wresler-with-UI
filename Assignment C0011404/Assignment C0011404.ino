#include <Wire.h>
#include <Zumo32U4.h>

#define NUM_SENSORS 5

unsigned int lineSensorValues[NUM_SENSORS];
// linesence 0 is left 2 is front 4 is right

int16_t lastError = 0;
const uint16_t maxSpeed = 200;
int16_t ModeSelection = 0;

Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
Zumo32U4Buzzer buzzer;

const char oops[] PROGMEM = "v12 L16 o4 frc32<b32c32c#8cr8.erf";
const char BootUp[] PROGMEM = "v12 L16 o4 c8.e8f#8ag8.e8c8<a<f#<f#<f#<g";
void setup(){
  Serial1.begin(9600); 
  lineSensors.initFiveSensors();  //two of the sensors were not functional
  proxSensors.initThreeSensors();
  char input = (char) Serial.read();
  Serial1.println("Press Space to start");
}

void LineCheck(){
  lineSensors.readLine(lineSensorValues);
  while (lineSensorValues[0] > 700 or lineSensorValues[2] > 700){ //if the front or left sensor goes off the robot goes right
    motors.setSpeeds(150, -150);
    delay(150);
    motors.setSpeeds(0,0);
    lineSensors.readLine(lineSensorValues);
  } while (lineSensorValues[4] > 800){ // if the right sensor goes off it turns left
    motors.setSpeeds(-150, 150);
    delay(150);
    motors.setSpeeds(0,0);
    lineSensors.readLine(lineSensorValues);
  }  
}

int Bonuses(){
  lineSensors.readLine(lineSensorValues);
  if (400 > lineSensorValues[0] > 200 or 400 > lineSensorValues[2] > 200 or 400 > lineSensorValues[4] > 200){
    return 1;
  }else if (750 > lineSensorValues[0] > 450 or 750 > lineSensorValues[0] > 450 or 750 > lineSensorValues[0] > 450){
    return 2;    
  }else{return 0;}
}

void calibrateSensors()
{

  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motors.setSpeeds(-200, 200);
    }
    else
    {
      motors.setSpeeds(200, -200);
    }
    lineSensors.calibrate();
  }
  motors.setSpeeds(0, 0);
}


void loop(){
  int incomingByte = 0;
  int loop = 0;
  int PerCheck = 0;
  if (Serial1.available() > 0) {
    Serial1.println("Select Mode: 1 - Manual, 2 - Auto, 3 - DebugMode"); //menu for the options
    ModeSelection = Serial1.read();
    while (ModeSelection == 49){
      incomingByte = Serial1.read();
      if (incomingByte == 119){ //movement works as labled and the serial input is different keys being pressed (wasdqe)
        motors.setSpeeds(385, 400); //when going forwards there was drift this acounted for that, your mileage may vary
        Serial1.println("Going forwards");
        delay(70);
        motors.setSpeeds(0, 0);
      } else if (incomingByte == 115) {
        motors.setSpeeds(-400, -400);
        Serial1.println("Going backwards");
        delay(70);
        motors.setSpeeds(0, 0);
      } else if (incomingByte == 97){
        motors.setSpeeds(-400, 400);
        Serial1.println("Going left");
        delay(40);
        motors.setSpeeds(0, 0);
      } else if (incomingByte == 100){
        motors.setSpeeds(400, -400);
        Serial1.println("Going right");
        delay(40);
        motors.setSpeeds(0, 0);
      }else if (incomingByte == 108){ //the L key takes the user out of the current program
        ModeSelection = 0;        
      } 
      
      } while (ModeSelection == 50){ //room search with a stop if it comes across a person
      incomingByte = Serial1.read();      
      if (incomingByte == 108){
        ModeSelection = 0;        
      } else if (loop == 0){
        calibrateSensors();  //calibration only occurs once per run
        loop = 1;
      }
      LineCheck();
      proxSensors.read();
      int left_sensor = proxSensors.countsLeftWithLeftLeds();
      int center_left_sensor = proxSensors.countsFrontWithLeftLeds();
      int center_right_sensor = proxSensors.countsFrontWithRightLeds();
      int right_sensor = proxSensors.countsRightWithRightLeds(); 
      if (center_left_sensor < left_sensor && left_sensor > 4){
        motors.setSpeeds(-200, 200);
        delay(100);        
      }else if (right_sensor > center_right_sensor && right_sensor > 4){
        motors.setSpeeds(200, -200);
        delay(100);
      }else {
        motors.setSpeeds(200, 200);
      }
      int BonusCheck = Bonuses();
      

    } while (ModeSelection == 51){
      proxSensors.read();
      int left_sensor = proxSensors.countsLeftWithLeftLeds();
      int center_left_sensor = proxSensors.countsFrontWithLeftLeds();
      int center_right_sensor = proxSensors.countsFrontWithRightLeds(); //testing for the proximity sensors
      int right_sensor = proxSensors.countsRightWithRightLeds(); 
      Serial1.println(left_sensor);     
      Serial1.println(center_left_sensor);
      Serial1.println(center_right_sensor);
      Serial1.println(right_sensor);
      delay (500) ;
      incomingByte = Serial1.read(); //a simple way of finding what keys corrospond to what numbers
      Serial1.println(incomingByte);
      delay(1000);
      if (incomingByte == 108){
        ModeSelection = 0;
      }      
    }
    
  }
}
