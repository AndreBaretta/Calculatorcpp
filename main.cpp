#include <iostream>
#include "keyboard.cpp"


int main(){
   memory mem;
   processor p1(mem);
   keyboard kb(p1);
  
   kb.teste();
}
