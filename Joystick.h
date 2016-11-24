#ifndef Joystick_h
#define Joystick_h
//#include <Arduino.h>
#include "Arduino.h"

  # define serialPressed         'e'
  # define serialUp              'w'
  # define serialDown            's'
  # define serialLeft            'a'
  # define serialRight           'd'

  #define analog_up_max           300     // Joystick Up
  #define analog_down_min         850     // Joystick Down
  #define analog_left_max         300     // Joystick Left
  #define analog_right_min        850     // Joystick Right
  #define joystickTime            300     // Time between pressing the joystick

  # define _joystickPressed      4
  # define _joystickRight        3
  # define _joystickLeft         2
  # define _joystickUp           1
  # define _joystickDown         0


class Joystick{
  public:
    Joystick(uint8_t pin_VRX, uint8_t pin_VRY, uint8_t pin_SW);
    boolean isPressed();
    void setPressed();
    void resetPressed();
    
    boolean isRight();
    void setRight();
    void resetRight();
    
    boolean isLeft();
    void setLeft();
    void resetLeft();
    
    boolean isUp();
    void setUp();
    void resetUp();
    
    boolean isDown();
    void setDown();
    void resetDown();
    
    void reset();
    void verifyJoystick();
    void status();

  private:
    uint8_t _joystick;
    uint8_t _pin_VRX;
	  uint8_t _pin_VRY;
	  uint8_t _pin_SW;
	  long _elapsedJoystickTime;
};
#endif

