#include <iostream>
#include <string>

class screen {
   public:
      void showOp(double num, std::string op, double num2){
         std::cout << num << " " << op << " " << num2 << " = " << std::endl;
      }
      void showRes(double res){
         std::cout << res << std::endl;
      }
};
