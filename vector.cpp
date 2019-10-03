#include <iostream>
#include <vector>

main(int argc, char const *argv[])
{
    std::vector<int> array;
    std::vector<int> array2 = {9, 7, 5, 3, 1}; // use initializer list to initialize array
    std::vector<int> array3{9, 7, 5, 3, 1};    // use uniform initialization

    array[6] = 2;      // no bound checking
    array.at(7) = 3;   // bound checking
    array = {9, 8, 7}; // now array length is 3

    array.resize(5); // set size to 5
    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element : array)
        std::cout << element << ' ';
    
    std::vector<bool>byte_array{true,false,false,true,true};
    std::cout << "The length is : "<< byte_array.size()<<'\n';

    for(auto const &element : array)
        std::cout <<element<< ' ';
    return 0;
}
