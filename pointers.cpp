#include <iostream>
#include <typeinfo> // for typeid().name()
#include <cstddef>  // for nullptr_t

void doSomething(std::nullptr_t) // type nullptr_t only holds nullptr
{
    std::cout << "In doSomething()\n";
}

void pointer_to_const()
{
    const int value = 5;
    const int *ptr = &value; // non-const pointer that is pointing to a "const int"
    *ptr = 6;                // not allowed, we can't change a const value

    int value2 = 5;
    int *const k_ptr = &value2; // initialized
    *k_ptr = 6;
    k_ptr = &value; // not ok, const pointer can not be changed.

    const int value3 = 5;
    const int *const ptr = &value3; // const pointer to const value
}
int main()
{
    int x = 5;
    std::cout << x << '\n';
    std::cout << &x << '\n';  // print memory address of variable x
    std::cout << *&x << '\n'; // print the value at the memory address of variable x

    int value = 5;
    int *ptr = &value; // initialize ptr with address of variable value

    std::cout << typeid(&x).name(); // show data type of &x -> int*

    int *nulpt{nullptr}; // declare the variable pointer to nullptr: 0

    doSomething(nullptr); // call doSomething with an argument of type std::nullptr_t

    int array[5] = {9, 7, 5, 3, 1};
    std::cout << &array[1] << '\n'; // print memory address of array element 1
    std::cout << array + 1 << '\n'; // print memory address of array pointer + 1

    std::cout << array[1] << '\n';     // prints 7
    std::cout << *(array + 1) << '\n'; // prints 7 (note the parenthesis required here)

    return 0;
}
