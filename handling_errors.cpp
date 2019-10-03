#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // for exit()

void printString(const char *cstring)
{
    if (cstring) // only if cstring is non-null
        std::cout << cstring;
    else
        std::cerr <<"function printString() received a null parameter";
}

int getArrayValue(const std::array<int,10> &array, int index)
{
    // use if statement to detect violated assumption
    if (index <0 || index >= array.size())
        //return -1; // return error code to caller
        exit(2); // terminate program and return error number 2 to OS
    return array[index];
}

int main(int argc, char const *argv[])
{
    std::string hello = "Hello, world!";
    int index;

    do
    {
        std::cout << "Enter an index: ";
        std::cin >> index;

        // handle case where user entered a non-integer
        if (std::cin.fail())
        {
            std::cin.clear();             // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer

            index = -1; // ensure index has an invalid value so the loop doesn't terminate
            continue;   // this continue may seem extraneous, but it explicitly signals an intent to terminate this loop iteration
        }

        // .. just in case we added more stuff here later
    } while (index < 0 || index >= hello.size()); // handle case where user entered an out of range integer

    std::cout << "Letter #" << index << " is " << hello[index] << std::endl;

    return 0;
}
