#include "Joystick.h"

Joystick::Joystick(uint8_t pin_VRX, uint8_t pin_VRY, uint8_t pin_SW){
	Serial.begin(9600);
	pinMode(pin_VRX,INPUT);
	pinMode(pin_VRY,INPUT);
	pinMode(pin_SW,INPUT_PULLUP);
	_pin_VRX = pin_VRX;
	_pin_VRY = pin_VRY;
	_pin_SW = pin_SW;
	_elapsedJoystickTime = 0;
  _joystick = 0;
}

// ********** Press ***************
boolean Joystick::isPressed(){
  return bitRead(_joystick, _joystickPressed);
}
void Joystick::setPressed(){
    bitSet(_joystick, _joystickPressed);
}
void Joystick::resetPressed(){
    bitClear(_joystick, _joystickPressed);
}

// ********** Right ***************
boolean Joystick::isRight(){
  return bitRead(_joystick, _joystickRight);
}
void Joystick::setRight(){
    bitSet(_joystick, _joystickRight);
}
void Joystick::resetRight(){
    bitClear(_joystick, _joystickRight);
}

// ********** Left ***************
boolean Joystick::isLeft(){
  return bitRead(_joystick, _joystickLeft);
}
void Joystick::setLeft(){
    bitSet(_joystick, _joystickLeft);
}
void Joystick::resetLeft(){
    bitClear(_joystick, _joystickLeft);
}

// ********** Up ***************
boolean Joystick::isUp(){
  return bitRead(_joystick, _joystickUp);
}
void Joystick::setUp(){
    bitSet(_joystick, _joystickUp);
}
void Joystick::resetUp(){
    bitClear(_joystick, _joystickUp);
}

// ********** Down ***************
boolean Joystick::isDown(){
  return bitRead(_joystick, _joystickDown);
}
void Joystick::setDown(){
    bitSet(_joystick, _joystickDown);
}
void Joystick::resetDown(){
    bitClear(_joystick, _joystickDown);
}

// ********** Reset ***************
void Joystick::reset(){
    bitClear(_joystick, _joystickPressed);
    bitClear(_joystick, _joystickRight);
    bitClear(_joystick, _joystickLeft);
    bitClear(_joystick, _joystickUp);
    bitClear(_joystick, _joystickDown);
}

// ********** Verify ***************
void Joystick::verifyJoystick(){
	if((millis()-_elapsedJoystickTime)>joystickTime){
		// ********** Serial ***************
		if (Serial.available()) {
			// read one char from input buffer
			switch (Serial.read())
			{
			case serialPressed:   setPressed(); 	break;
			case serialUp:     	  setUp();    	  break;
			case serialDown:    	setDown();    	break;
			case serialLeft:    	setLeft();    	break;
			case serialRight:   	setRight();    	break;
			default: break;
			}
		}

		// ********** Joystick ***************
		if(analogRead(_pin_VRX)<analog_left_max)	{setLeft();}
		if(analogRead(_pin_VRX)>analog_right_min)	{setRight();}
		if(analogRead(_pin_VRY)<analog_up_max)		{setUp(); }
		if(analogRead(_pin_VRY)>analog_down_min)	{setDown();}
		if(!digitalRead(_pin_SW))  		      			{setPressed();}
	}
}


// ********** Test ***************
void Joystick::test(){  
  Serial.print("  || isPressed: "); Serial.print(this->isPressed());
  Serial.print("  || isUp: "); Serial.print(this->isUp());
  Serial.print("  || isDown: "); Serial.print(this->isDown());
  Serial.print("  || isRight: "); Serial.print(this->isRight());
  Serial.print("  || isLeft: "); Serial.println(this->isLeft());
  delay(1000);
 
}















