#include <iostream>
#include <string>

main(int argc, char const *argv[])
{
    int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 3, 21, 34, 55, 89};
    for (auto number : fibonacci)   // iterate over array fibonacci, type is auto : deduced from array
        std::cout << number << ' '; // elements accessed through variable number

    int array[5] = {9, 7, 5, 3, 1};
    for (auto &element : array) // reference: prevent copying the array element
        std::cout << element << ' ';
    for (const auto &element : array)
        std::cout << element << ' '; // element is a const reference to the currently iterated array element

    return 0;
}

void enter_name()
{
    std::string array[] = {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::string name;
    std::cout << "Choose name: ";
    std::cin >> name;
    for (const auto &element : array)
        if (element == name)
        {
            std::cout << name << " was found." << std::endl;
            break;
        }
}