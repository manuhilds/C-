#include <iostream>
#include <array>
#include <algorithm> // for std::sort

std::array<int, 3> myArray; // declare an integer array with length 3

std::array<int, 5> myArray2 = {9, 7, 5, 3, 1}; // initialization list

void printLength(const std::array<double, 5> &myArray)
{
    std::cout << "length" << myArray.size();
}

int main(int argc, char const *argv[])
{
    myArray.at(1) = 6; // array element 1 valid, sets element 1 to value 6
    myArray.at(4) = 5; // array element 4 invalid : will throw error
    std::array<double, 5> yoArray = {9.0, 7.2, 5.4, 3.6, 1.8};
    printLength(yoArray);

    std::sort(myArray2.begin(), myArray2.end()); // sort the array forwards (rbegin + rend for backwards)

    for (auto &element : myArray2)
        std::cout << element << ' ';

    using index_t = std::array<int, 5>::size_type;
    for (index_t i{0}; i < myArray2.size(); ++i)
        std::cout << myArray2[i] << ' ';
    return 0;
}
