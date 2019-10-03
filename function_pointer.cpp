#include <iostream>
#include <utility> // for std::swap
#include <functional> // std::functions


typedef bool (*validateFcn) (int,int); // defines a typedef "validateFcn" -> pointer to function that takes 2 int
using validatey= bool(*)(int,int);
void SelectionSort(int *array, int size, validateFcn pfcn = ascending)
{
    // Step through each element of the array

    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // bestIndex is the index of the smallest element we've encountered so far.
        int bestIndex = startIndex;

        // look for smalles element remaining in the array (starting at startIndex+1)

        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            if (pfcn(array[bestIndex], array[currentIndex]))
                bestIndex = currentIndex;
        }
        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

bool ascending(int x, int y)
{
    return x > y; // swap if the first elemet is greater than the second.
}

bool descending(int x, int y)
{
    return x < y;
}

bool evenFirst(int x, int y)
{
    if ((x % 2 == 0) && !(y % 2 == 0))
        return false;
    if (!(x % 2 == 0) && (y % 2 == 0))
        return true;
}     // 
void printArray(int *array, int size)
{

    for (int index = 0; index < size; ++index)
    {
        std::cout << array[index] << " ";
    }
    std::cout << '\n';
}


// using functional
bool validate (int x, int y, std::function<bool(int,int)> fcn);




int foo(int x)
{
    return 5;
}

int goo(int x)
{
    return 6;
}
int (*const fcnPtr)();
main(int argc, char const *argv[])
{
    std::cout << reinterpret_cast<void *>(foo);

    // fncPtr is a pointer to a function that takes no arguments and returns an integer
    int (*fcnPtr)(int) = foo; // fcnPtr points to function foo
    fcnPtr = goo;             // fcn now points to function goo;
    (*fcnPtr)(5);             // call function foo(5) through fncPtr;

    int array[9] = {3, 7, 9, 5, 6, 1, 8, 2, 4};

    SelectionSort(array, 9, descending);
    printArray(array, 9);

    SelectionSort(array, 9, ascending);
    printArray(array, 9);

    return 0;
}


#pragma 