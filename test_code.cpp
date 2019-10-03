

// while testing aim for 100% statement coverage

#include <iostream>
#include <string>

void compare(int x, int y)
{
    if (x > y)
        std::cout << x << " is greater than " << y << '\n'; // case 1
    else if (x < y)
        std::cout << x << " is less than " << y << '\n'; // case 2
    else
        std::cout << x << " is equal to " << y << '\n'; // case 3
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter a number ";
    int x;
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y;
    std::cin >> y;

    compare(x, y);
    return 0;
}

