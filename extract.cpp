// make the program robust
// std::cin, buffers, and extraction
// >> operator is called extraction

// input validation : process of checking whether user input conforms to what the program is expecting

// inline : prevent the user from typing invalid input in the first place
// Post-entry:
// - let the user enter whatever they want into a string, then validate whether the string is correct, if so, convert the string to the final variable format
// - Let the user enter whatever they want, let std::cin and operator>> try to extract it, and handle the error cases.

// error case A: Extraction succeeds but input is meaningless : ex: 'q' was entered
// error case B: Extraction succeeds but with extraneous input
// error case C: Extraction fails
// error case D: Extraction succeeds but the user overflows a numeric value

#include <iostream>

double getDouble()
{
    while(true) // Loop until user enters a valid input
    {
        std::cout << "Enter a double value: ";
        double x;
        std::cin >> x;
        if (std::cin.fail())// has a previous user enters a valid input
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed
            std::cout <<"Oops, that input is invalid. Please try again.\n";
        }
        else 
        {
            std::cin.ignore(32767,'\n');
            return x;
        }
            
    }
}

char getOperator()
{
    while (true) //loop until user enters a valid input
    {
        std::cout << "Enter one of the following: +, -, *, or /: ";
        char op;
        std::cin >> op;

        std::cin.ignore(32767,'\n');
        //Check whether the user entered meaningful input
        if (op == '+' || op == '-' || op == '*' || op == '/')
            return op; // return it to the caller
        else // otherwise tell the user what went wrong
            std::cout <<"Oops, that input is invalid. Please try again. \n";
    } // and try again
}

void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
    else 
        std::cout <<"Something went wrong: printResult() got an invalid operator.";
}

int main()
{
    double x = getDouble();
    char op = getOperator();
    double y = getDouble();

    printResult(x, op, y);

    return 0;
}
