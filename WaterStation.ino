#include "Joystick.h"
#include "Arduino.h"
#include "Menu.h"

//#define pin_VRX           A2
//#define pin_VRY           A3
//#define pin_SW            A7

uint8_t pin_VRX      =     A2; //must be analog
uint8_t pin_VRY      =     A3; //must be analog
uint8_t pin_SW       =     10; //must be digital

Menu menu = Menu();
Joystick joystick = Joystick(pin_VRX, pin_VRY, pin_SW);


void setup(){
  Serial.begin(9600);Serial.print("Teste");
  
  }

void loop(){
  joystick.verifyJoystick();
  joystick.status();  
  joystick.reset();
  }
