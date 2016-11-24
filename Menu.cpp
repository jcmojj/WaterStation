#include "Menu.h"

Menu::Menu(){
  
}

void Menu::display(){
  
}

byte Menu::getMenu(){return 0;

}

byte Menu::setMenu(){return 0;

}

byte Menu::getCursor(){
  return 0;
}

byte Menu::setCursor(){return 0;

}

byte  Menu::petChangeStatus(byte pet){
  if(bitRead(_petsStatus, pet)){
    bitClear(_petsStatus, pet);
    }else{
      bitSet(_petsStatus, pet);
    }
}

boolean Menu::petIsActivated(byte pet){
  return bitRead(_petsStatus, pet);
}

