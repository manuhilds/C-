#include <iostream>

void changeN(int &ref)
{
    // ref is a reference to the argument passed in, not a copy
    ref = 6;
}

void constchangN(const int &ref)
{
    ref = 6; // not allowed, ref is const
}
void printElement(int (&arr)[4])
{
    int length{sizeof(arr) / sizeof(arr[0])}; // we can now do this since the array won't decay

    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}


struct Something
{
    int value1;
    float value2;
};


struct Other
{
    Something something;
    int otherValue;
};

Other other;

int &struct_ref = other.something.value1;
// ref can now be used in place of other.something.value1


void reference_vs_pointer()
{

    int value = 5;
    int *const ptr = &value;
    int &ref = value;

    // both statement produce the same effect:
    *ptr = 5;
    ref = 5;
}

int main()
{
    int value = 5;    // normal integer
    int &ref = value; // reference to variable value

    value = 6; // value is now 6
    ref = 7;   // value is now 7

    std::cout << value; // prints 7
    ++ref;
    std::cout << value; // prints 8

    const int y = 7;
    int &ref2 = y; // not ok, y is a const l-value
    int &ref3 = 6; // must be defined with l value not r value

    int n = 5;
    std::cout << n << '\n';
    changeN(n); // note that this argument does not need to be a reference

    std::cout << n << '\n';

    int arr[]{99, 20, 14, 80};
    printElement(arr);


    const int k_value = 5;
    const int &k_ref = value; // ref is a reference to const value
    int x = 5;
    const int &k_ref1 = x; // ok, x is a non-const l-value

    const int k_y = 7;
    const int &k_ref2 = k_y; // ook, y is a const l-value

    cont int &k_ref3 = 6; // ok, 6 is a r-value
    return 0;
}