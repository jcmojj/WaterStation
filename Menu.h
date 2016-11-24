#ifndef Menu_h
#define Menu_h
#include "Arduino.h"


  # define _joystickPressed      4
  # define _joystickRight        3
  # define _joystickLeft         2
  # define _joystickUp           1
  # define _root                 0

class Menu{
  public:
  void display();
  uint8_t getMenu();
  uint8_t setMenu();
  uint8_t getCursor();
  uint8_t setCursor();

    private:
    /* current cursor position */
    uint8_t   _currentCursor;     //curlos
    /* current scroll position */
    uint8_t   _currentScroll; //scroll
    /* save the last cursor position when a menu element is called */
    uint8_t   _lastCursorPosistion; //cursor_pos
    /* how many childs exists on next layer */
    uint8_t   _childsQty; //child_cnt
    /*  */
    uint8_t _menu;
    /* containes the current layer */
    uint8_t   _curLayer; //layer  
  
}

#endif
