#include <iostream>

using namespace std;

namespace mynamespace
{
const int numbers = 0;
const char *greetings = "Hello !";
} // namespace mynamespace


int main()
{
    cout << mynamespace::numbers << endl;
    cout << mynamespace::greetings << endl;
    return 0;
}

/// blocks

int main()
{
    std::cout << "Enter an integer: ";
    int smaller;
    std::cin >> smaller;

    std::cout << "Enter a largeur integer: ";
    int larger;
    std::cin >> larger;

    // if user did it wrong
    if (smaller > larger)
    {
        //swap values of smaller and larger
        std::cout << "Swapping the values\n";

        int temp = larger;
        larger = smaller;
        smaller = temp;
    } // temp dies here

    std::cout <<"The smaller value is : " << smaller << std::endl;
    std::cout << "The larger value is : " << larger << std::endl;
    return 0;
} // smaller and larger die here.

