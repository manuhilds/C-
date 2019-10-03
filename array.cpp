#include <iostream>
#include <utility>
#include <algorithm>
struct Rectangle
{
    int length;
    int width;
};
enum Animals
{
    ANIMAL_CAT = 2
};
namespace StudentNames
{
enum StudentNames
{
    KENNY,
    KYLE,
    STAN,
    BUTTERS,
    CARTMAN,
    WENDY,
    MAX_STUDENTS
};
}

void passArray(const int prime[5]) // pass array as const so that it doesn't change
{
    prime[0] = 11; // thanks to const the array can't be changed
}
int main()
{
    // declare array
    int prime[4];
    Rectangle rects[5]; // declaring array of 5 struct Rectangle
    prime[0] = 5;       // indexing an array
    prime[ANIMAL_CAT] = ANIMAL_CAT;

    int testScores[StudentNames::MAX_STUDENTS];
    testScores[StudentNames::STAN] = 76;

    int array[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int length = sizeof(array) / sizeof(array[0];
    std::cout << "The array has: " << length << "elements\n";

    int x = 2;
    int y = 4;

    std::swap(x,y);
    std::sort(array, array+length);

    int md_array[][5] =
    {
        {1,2,3,4,5},
        {6,7,8,9,10}
    };
    return 0;
}