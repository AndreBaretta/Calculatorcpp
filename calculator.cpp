#include "stdio.h"
#include <iostream>
#include <string>

class Calculator {
public:
    Calculator() {
        Screen screen;
        Memory memory;
        Processor processor(screen, memory);

        // B1(screen);
        // B1(screen);
        // B2(screen);
        // BMais(memory, screen);
        // B3(screen);
        // B4(screen);
        // BMenos(memory, screen);
        // B5(screen);
        // BEnter(memory, screen, processor);

        std::cout << screen.get() << std::endl;
    }
};

int main() {
    Calculator calculator;
    return 0;
}

class Button
{
    public:
};

