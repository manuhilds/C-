#include <iostream>
#include <vector>

void printStack(const std::vector<int> &stack)
{
    for (const auto &element : stack)
        std::cout << element << ' ';
    std::cout << "(cap" << stack.capacity() << " length " << stack.size() << ")\n";
}
int main(int argc, char const *argv[])
{
    std::vector<int> array{0, 1, 2};
    array.resize(5);
    array.reserve(5); //as resize too expensive

    std::cout << "The length is: " << array.size() << '\n';

    for (auto const &element : array)
        std::cout << element << ' ';

    std::vector<int> stack;

    printStack(stack);

    stack.push_back(5); // pushes an element on the stack
    printStack(stack);
    stack.push_back(3);
    printStack(stack);
    std::cout << "top: " << stack.back() << '\n'; // return last element

    stack.pop_back(); // pops en element off the stack
    printStack(stack);


    return 0;
}
