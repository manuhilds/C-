#include "Class.hpp"
#include <iostream>

enum class Config{
    YOUT8,
    MYFILE,
    SER
};

enum status{
    GOOD,
    GOOD_ENOUGH,
    NOT_GOOD_ENOUGH,
};

struct Hello{
    int myFile;
    float number;
};

struct bye{
    int ID;
    Hello goodbye;
};

bye concept(bye input)
{
    
    if (input.goodbye.myFile == GOOD) {
        input.goodbye.myFile = GOOD_ENOUGH;
        return input;
    }
    
}

typedef struct bye Bye_t;

int main()
{
   Bye_t me ={0,{5,6.0}};
   concept(me);

    return 0;
}