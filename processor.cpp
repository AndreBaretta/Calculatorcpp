#include <iostream>
#include <string>
#include "memory.cpp"
#include "screen.cpp"

class processor {
   public:
      processor(memory& memory, screen& screen) : mem(memory), scr(screen){}
     
      void keyPressed(const std::string& label){
      
         try {
            digit = std::stoi(label);
            bl = 1;
         } 
         catch(...) {
            bl = 0;
         }

         if(bl == 1 || label == "."){
            currentNum += label;
         }else if(label == "+" || label == "-" || label == "*" || label == "/"){
            currentOp = label;
            if(t == 0){
               mem.store(std::stod(currentNum));
               t++;
            }
            currentNum = "";
         }else if(label == "="){
               calculate();
         }else if(label == "C"){
            clear();
         }else if(label == "CE"){
            clearEntry();
         }else{
            error();
         }
      }

   private:
      int t = 0;
      int digit;
      int bl;
      double result;
      std::string currentNum;
      std::string currentOp;
      memory& mem;
      screen& scr;
      void calculate(){
         if(!currentNum.empty() && !currentOp.empty()){
            double num = std::stod(currentNum);
            double result = mem.getMemory();
            scr.showOp(result, currentOp, num);
            scr.showRes(result);
            if(currentOp == "+"){
               result += num;
            }else if(currentOp == "-"){
               result -= num;
            }else if(currentOp == "*"){
               
               result *= num;
            }else if(currentOp == "/"){
               if(num != 0){
                  result /= num;
               }else{
                  error();
               }
            }
            std::cout << result << std::endl;
            mem.store(result);
         }
      }
      void clear(){
         currentNum = "";
         currentOp  = "";
         mem.clear();
         std::cout << "CLEARED" << std::endl;
      }
      void error(){
         std::cout << "ERROR" << std::endl;
      }
      void clearEntry(){
         currentNum = "";
      }
};
