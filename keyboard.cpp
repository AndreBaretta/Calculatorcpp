#include <iostream>
#include <string>
#include "keys.cpp"
#include "processor.cpp"

class keyboard {
   public:
      keyboard(processor& processor) : p1(processor){}

      void registerr(std::string label){
        p1.keyPressed(label);
      }
      
      void teste(){
         registerr(b2.press());
         registerr(b0.press());
         registerr(bp.press());
         registerr(b2.press());
         registerr(beq.press());
         registerr(bt.press());
         registerr(b3.press());
         registerr(beq.press());
         registerr(bc.press());
      }

   private:
      processor& p1;
      key beq{"="}; 
      key bp{"+"}; 
      key bm{"-"}; 
      key bt{"*"}; 
      key bd{"/"}; 
      key bc{"C"}; 
      key bce{"CE"}; 
      key bpt{"."}; 
      key b0{"0"}; 
      key b1{"1"}; 
      key b2{"2"}; 
      key b3{"3"}; 
      key b4{"4"}; 
      key b5{"5"}; 
      key b6{"6"}; 
      key b7{"7"}; 
      key b8{"8"}; 
      key b9{"9"}; 
};
