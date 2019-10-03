#include <cassert> // for assert()
#include <array> 
#include <iostream>
#define NDEBUG // all assert calls will now be ignored 

int getArrayValue(const std::array<int, 10> &array, int index)
{
    // we're asserting that index is between 0 and 9 
    assert(index >=0 && index <= 9); // this is line 6 in Test.cpp

    return array[index];
}

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) == 4, "int must be 4 bytes");

int main(int argc, char const *argv[])
{   
    bool found;
    assert(found && "Car could not be found in database");
    return 0;
}
