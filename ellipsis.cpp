#include <iostream>
#include <cstdarg> // needed to use ellipsis

// The ellipsis must be the last parameter
// cont is how many additional arguments we're passing

double findAverage(int count, ...)
{
    double sum = 0;
    // We access the ellipsis through a va_list, so let's declare one
    va_list list;
    // We initialize the va_list using va_start. The first parameter is
    // the list to initialize. The second parameter is the last non-ellipsis
    // parameter.
    va_start(list, count);

    // Loop through all the ellipsis arguments
    for(int arg = 0; arg < count; ++arg)
    {
        // We use va_arg to get paramters out of our ellipsis
        // The first paramter is the va_list we're using
        // The second parameter is the type of the parameter
        sum += va_arg(list, int);
    }

    // Cleanup the va_list when we're done.
    va_end(list);

    return sum / count;
    
}

int main()
{
    std::cout << findAverage(5,1,2,3,4,5) <<'\n';
    std::cout << findAverage(6,1,2,3,4,5,6) <<'\n';
}