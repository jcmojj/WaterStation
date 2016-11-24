#ifndef Menu_h
#define Menu_h
#include "Arduino.h"
#include <avr/pgmspace.h> //PROGMEM

  #define NUMBER_OF_ELEMENTS  7
  #define MAX_SIZE  12
  #define MENU_SIZE  11
  # define _joystickPressed      4
  # define _joystickRight        3
  # define _joystickLeft         2
  # define _joystickUp           1
  # define _root                 0

//****************** Menu ******************
const char descriptions [MENU_SIZE] [NUMBER_OF_ELEMENTS] [MAX_SIZE] PROGMEM = 
// abcd a=menuIndexName b=fatherMenuIndex c=fatherSubmenuIndex d=thisSubmenuQty efghij=sonMenuIndex
{
{ { "aa05bcfghk" }, 
  { "MyKidPet" }, 
  { "Pets" }, 
  { "Dono" }, 
  { "Opcoes" }, 
  { "Ajustes" },    
  { "" }, },

{ { "ba13" }, 
  { "Adiciona" }, 
  { "Apaga" }, 
  { "Inverte" }, 
  { "" }, 
  { "" },    
  { "" }, },

{ { "ca26" }, 
  { "Todos" }, 
  { "Pet1" }, 
  { "Pet2" }, 
  { "Pet3" }, 
  { "Pet4" },    
  { "Pet5" }, },

// a_bcd a=menuIndex b=fatherMenuIndex c=fatherSubmenuIndex
{ { "dc14" }, 
  { "Ultima vez" }, 
  { "Ultima dia" }, 
  { "Ultima sem" }, 
  { "Ultima ano" }, 
  { "" },    
  { "" }, },


{ { "ec23" }, 
  { "Nome" }, 
  { "Tag" }, 
  { "Info" }, 
  { "" }, 
  { "" },    
  { "" }, },


{ { "fe26" }, 
  { "Sem cor" }, 
  { "Vermelho" }, 
  { "Azul" }, 
  { "Preto" }, 
  { "Branco" },    
  { "Verde" }, },

// a_bcd a=menuIndex b=fatherMenuIndex c=fatherSubmenuIndex
{ { "ga33" }, 
  { "Nome" }, 
  { "Celular" }, 
  { "Email" }, 
  { "" }, 
  { "" },    
  { "" }, },


{ { "ha44" }, 
  { "Modo" }, 
  { "Rede" }, 
  { "Data" }, 
  { "Hora" }, 
  { "" },    
  { "" }, },


{ { "ih12" }, 
  { "Por Volume" }, 
  { "Por Horario" }, 
  { "" }, 
  { "" }, 
  { "" },    
  { "" }, },

// a_bcd a=menuIndex b=fatherMenuIndex c=fatherSubmenuIndex
{ { "jh22" }, 
  { "Nome" }, 
  { "Senha" }, 
  { "" }, 
  { "" }, 
  { "" },    
  { "" }, },

{ { "ka53" }, 
  { "Brilho" }, 
  { "Contraste" }, 
  { "Tela acesa" }, 
  { "" }, 
  { "" },    
  { "" }, },
  };
//**************** Fim:Menu ****************

class Menu{
  public:
    Menu();
    void display();
    byte getMenu();
    byte setMenu();
    byte getCursor();
    byte setCursor();
    char buffer[30];
    byte petChangeStatus(byte i);
    boolean petIsActivated(byte i);

    
  private:
    /* current cursor position */
    byte   _currentCursor;     // curloc
    /* current scroll position */
    byte   _currentScroll; //scroll
    /* save the last cursor position when a menu element is called */
    byte   _lastCursorPosistion; //cursor_pos -- fatherSubmenuIndex
    /* how many childs exists on next layer */
    byte   _childsQty; //child_cnt
    /* menuIndexName */
    byte   _menu;
    /* containes the current layer */
    byte   _curLayer; //layer      
    byte  _fatherMenuIndex;
    byte  _thisMenuQty;
    byte  _petsStatus;
};

#endif
