#include <iostream>
#include "keyboard.cpp"


int main(){
   memory mem;
   screen scr;
   processor p1(mem,scr);
   keyboard kb(p1);
  
   kb.teste();
}
