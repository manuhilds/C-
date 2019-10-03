#include <iostream>
#include <cmath> // for std::sin() and std::cos()

// pass by value
void foo(int y)
{
    std::cout << "y = " << y << '\n';
}

// pass by reference
void addOne(int &ref)
{
    ref = ref + 1;
}

// return multiple value
void getSinCos(double degrees, double &sinOut, double &cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    const double pi = 3.14159265358979323846; // value of pi
    double radians = degrees * pi / 180;
    sinOut = std::sin(radians);
    cosOut = std::cos(radians);
}

// reference to pointers

void foo(int *&ptr) // pass pointer by reference
{
    ptr = nullptr; // change of ptr passed in to the argument.
}

// c-style array with reference
void printElement(int (&arr)[4])
{
    int length{sizeof(arr) / sizeof(arr[0])}; // array won't decay
    for (int i{0}; i < length; ++i)
        std::cout << arr[i] << std::endl;
}
main(int argc, char const *argv[])
{
    // pass by value
    foo(5);
    int x = 6;
    foo(x);
    foo(x + 1);

    // pass by reference
    int value = 5;
    std::cout << "value = " << value << '\n';
    addOne(value);
    std::cout << "value = " << value << '\n';

    double sin(0.0);
    double cos(0.0);
    // getSinCos will return the sin and cos in variables sin and cos
    getSinCos(30.0, sin, cos);

    // pass pointer by reference
    x = 5;
    int *ptr = &x;
    std::cout << "ptr is " << (ptr ? "non-null" : "null") << '\n'; // prints non-null
    foo(ptr);
    std::cout << "ptr is :" << (ptr ? "non-null" : "null") << '\n'; // prints null

    // C-style array 
    int arr[] {99,20,14,80};
    printElement(arr);  
    return 0;
}




// pass by address

void foo(int *ptr)
{
    *ptr = 6;
}
void printArray(int *array, int length)
{
    if (!array)
        return;
    
    for(int  index = 0; index < length; ++index)
    {
        std::cout << array[index] << ' ';
    }
    
}

// pass by const address 
void printArray(const int *array, int length)
{
    
}
int main_addr()
{
    int value = 5;

    std::cout << "value" << value << '\n';
    foo(&value);
    std::cout << "value = " << value << '\n';


    int array[6] = {6,5,4,3,2,1};
    printArray(array, 6);
    return 0;
}