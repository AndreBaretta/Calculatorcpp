#include <iostream>
#include <string>
#include "memory.cpp"

class processor {
   public:
      processor(memory& memory) : mem(memory){}
     
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
      void calculate(){
         if(!currentNum.empty() && !currentOp.empty()){
            double num = std::stod(currentNum);
            double result = mem.getMemory();
            std::cout << std::endl;
            std::cout << result << std::endl;
            std::cout << currentOp << std::endl;
            std::cout << currentNum << std::endl;
            std::cout << "=" << std::endl;
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
