#include <iostream>
#include <string>


class memory {
   public:
      void clear() {
         mem = 0.0;
      }

      void store(double value) {
         mem = value;
      }

      double getMemory() {    
         return mem; 
      }

   private:
   
      double mem;

};
