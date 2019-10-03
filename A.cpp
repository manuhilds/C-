#include "stdafx.h"
#include <iostream>

//using namespace std;f

int getUserInput()
{
    std::cout << "Please enter an integer: ";
    int value;
    std::cin >> value;
    return value;
}

int getMathematicalOperation()
{
    std::cout << "Please enter which operator you want (1 = +, 2 = 6, 3 = *, 4 = /):";
    int op;
    std::cin >> op;

    // what if the user enters an invalid character?
    // We'll ignore this possibility for now

    return op;
}

int calculateResult(int x, int op, int y)
{
    // note : we use the == operator to compare two values to see if they are equal
    // we need to use if statements here because there's no direct way to convert op into the appropriate operator

    if (op == 1) // if user chose addition(#1)
        return x + y;
    if (op == 2) // if user chose subtraction(#2)
        return x - y;
    if (op == 3) // if user chose multiplication(#3)
        return x * y;
    if (op == 4) // if user chose division (#4)
        return x / y;

    return x + y; // if user passed in an invalid op, we'll do addition.

    // we discuss better error handling in future chapters
}

void printResult(int result)
{
    std::cout << "Your result is: " << result << std::endl;
}

int main()
{
    // Get first number from user
    int input1 = getUserInput();

    // Get mathematical operation from user
    int op = getMathematicalOperation();

    // Get second number from user
    int input2 = getUserInput();

    // Calculate result and store in temporary variable (for readability/debug-ability)
    int result = calculateResult(input1, op, input2);

    // Print result
    printResult(result);

    return 0;
}
