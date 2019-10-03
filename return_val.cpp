#include <iostream>
#include <tuple>
#include <array>

// return by address
int *doubleValue(int x)
{
    int value = x * 2;
    return &value; // return value by address
} // but value destroyed here

int *allocateArray(int size)
{
    return new int[size];
}

// return by reference
int &getElement(std::array<int, 25> &array, int index)
{
    // array[index] will not be destroyed when returned because the caller passed in the array
    return array[index];
}

// lifetime extension

int returnByValue()
{
    return 5;
}

int &returnByReference()
{
    static int x = 5; // static ensures x isn't destroyed when the function ends
    return x;
}


 // returning multiple values

 struct S
 {
     int m_x;
     double m_y;
 };

 S returnStruct()
 {
     S s;
     s.m_x = 5;
     s.m_y = 6.7;
     return s;
 }

std::tuple<int, double> returnTuple() // return a tuple that contains and int and a double
{
    return std::make_tuple(5, 6.7); // use std::make_tuple() as shortcut to make a tuple
}

int main(int argc, char const *argv[])
{

    // return by address
    int *array = allocateArray(25);
    // do stuff
    delete[] array;

    //return by reference
    std::array<int, 25> array_ref;

    // set the element of array with index 10 to the value 5
    getElement(array_ref, 10) = 5;
    std::cout << array[10] << '\n';

    // lifetime extension
    int value = returnByReference();   //ok : treated as return by value
    int &ref = returnByValue();        // not ok : r-value cannot bind to a non-const reference
    const int &cref = returnByValue(); // ok : lifetime of return value extended to the lifetime of cref

    // return multiple value 

    S s =returnStruct();
    std::cout << s.m_x< ' ' << s.m_y<< '\n';

    // tuple
    std::tuple<int, double> s = returnTuple(); // get tuple

    int a;
    double b;
    std::tie(a, b) = returnTuple();
    std::cout << a << ' ' << b << '\n';
    auto [a, b] = returnTuple();
    std::cout << std::get<0>(s) << ' ' << std::get<1>(s) << '\n'; // get<n> to get the nth element of the tuple

    return 0;
}

int sumTo(const int param)
{
    int count = 0;

    for (size_t i = 0; i < std::static_cast<size_t>(param); ++i)
    {
        count += i;
    }
    return count;
}