#include <iostream>

void countDown(int count)
{
    std::cout << "push " << count << '\n';
    if (count > 1)            // termination condition
        countDown(count - 1); // countDown() calls itself recursively
    std::cout << "pop " << count << '\n';
}

// because of terminaison condition:
// - coutDown(1) doesn't call coutDown(0)
// prints pop 1: and terminates
// coutDown(1) popped off and coutDown(2) goes off
// print pop 2

int sumTo(int sumto)
{
    if (sumto <= 0)
        return 0; // base case (termination condition) when user passed in an unexpected parameter (0 or negative)
    else if (sumto == 1)
        return 1; // normal base case (termination condition)
    else
        return sumTo(sumto - 1) + sumto; // recursive function call
}

// fibonacci
// 0 if n=0
// 1 if n=1
// f(n-1) + f(n-2) if n>1

int fibonacci(int number)
{
    if (number == 0)
        return 0; // base case (termination condition)
    if (number == 1)
        return 1; // base case (termination condition)
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main(int argc, char const *argv[])
{
    countDown(5);

    for (int count = 0; count < 13; ++count)
    {
        std::cout << fibonacci(count) << " ";
    }

    return 0;
}
