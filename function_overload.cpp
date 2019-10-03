#include <iostream>

int add(int x, int y)
{
    return x + y;
}

// function overloads
double add(double x, double y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

void getRandomValue(int &out);
void getRandomValue(double &out); // out passed by argument
