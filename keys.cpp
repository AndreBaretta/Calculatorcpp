#include <iostream>
#include <string>

class key{
   public:
      key(const std::string& label) : label(label) {}
      std::string press(){
         return label;
      }
   private:
      std::string label;
};
