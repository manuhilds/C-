#include <iostream>
void dy_all_array();
int main()
{
    new int;                // dynamically allocate an integer(and discard the result)
    int *ptr = new int;     // dynamically allocate an integer and assign the address to ptr so we can access it later
    *ptr = 7;               // assign value of 7 to allocated memory
    int *ptr1 = new int{6}; // initialization(uniform)

    delete ptr;    // return the memory pointed to by ptr to the OS : dangling pointer
    ptr = nullptr; // set ptr to be a null pointer

    int *value = new (std::nothrow) int; // value will be set to a null pointer if the integer allocation fails
    if (!value)
    {
        // Do error handling here
        std::cout << "Could not allocate memory";
    }
    if (!ptr)
        ptr = new int;
    delete ptr;

    int my_value = 5;
    int *my_ptr = new int; // allocate memroy
    delete ptr;            // return memory back to operatin system
    my_ptr = &my_value;    // old address lost, memory l eak results

    void dy_all_array();
    return 0;
}

void dy_all_array()
{
    std::cout << "Enter a positive integer: ";
    int length;
    std::cin >> length;

    int *array = new int[length](); // use array new. Note that length does not need to be constant, initialized to 0 ()
    std::cout << "I just allocated an array of integers of length" << length << '\n';
    array[0] = 5;   // set element 0 to value 5
    delete[] array; // use array delete to deallocate array
    // no set to nullptr needed as the scope immediately ended.

    int fixedArray[5] = {9, 7, 5, 3, 1};        // initialize fixed array
    int *new_array = new int[5]{9, 7, 5, 3, 1}; // initialize a dynamic array
}