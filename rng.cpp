/*  
std::rand  generates the next random number in the sequence. That number
 # problem .. prints the same sequence of number
std::srand sets the inital seed value to a value that is passed in by the caller.*/

#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime>   // for std::time()
#include <random>  // for std::mt19937

int getRandomNumber(int min, int max);
//generate a random number between min and max (inclusive)
//Assumes std::srand() has already been called
//Assumes max -min <= RAND_MAX

void mersenne_RNG();
// use of mersenne twister

int main(int argc, char const *argv[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock

    // Print 100 random numbers
    for (int count = 1; count <= 100; ++count)
    {
        std::cout << std::rand() << "\t";

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << "\n";
    }

    return 0;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    // static used for efficency, so we only calculate thie value once
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void mersenne_RNG()
{
    // Initilize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution<> die(1, 6);

    // Print a bunch of random numbers
    for (int count = 1; count <= 48; ++count)
    {
        std::cout << die(mersenne) << "\t"; // generate a roll the die here

        // If we've printed 6 numbers, start a new row
        if (count % 6 == 0)
            std::cout << "\n";
    }
}