#include <iostream>

inline int min(int x, int y)
{
    return x > y ? y : x;
}

main(int argc, char const *argv[])
{
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';
    // with inline it is the same as :
    std::cout << (5 > 6 ? 6 : 5) << '\n';
    return 0;
}
