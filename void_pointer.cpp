#include <iostream>


int main(int argc, char const *argv[])
{
    int nValue;
    float fValue;

    struct Something
    {
        int n;
        float f;
    };

    Something sValue;

    void *ptr; // ptr is a void pointer
    ptr = &nValue; 
    ptr = &fValue;
    ptr = &sValue;

    int value = 5;
    void *voidPtr = &value;

    // cout << *voidPtr << endl; // illegal: cannot dereference a void pointer

    int *intPtr = static_cast<int*>(voidPtr); // however, if we cast our void pointer to an int pointer...
    
    std::cout << *intPtr <<std::endl; // then we can dereference it like normal
    return 0;
}


enum Type 
{
    INT,
    FLOAT,
    CSTRING
};

void printValue(void *ptr, Type type)
{
    
    switch (type)
    {
        case INT:
            std::cout << *static_cast<int*>(ptr) <<'\n'; // cast to int pointer + dereference
            break;
        
        case FLOAT:
            std::cout << *static_cast<float*>(ptr)<<'\n'; // cast to float pointer + dereference
            break;
        
        case CSTRING:
            std::cout << static_cast<char*>(ptr) <<'\n'; // cast to char pointer (no dereference)
            break;
    
        default:
            break;
    }
}

void la ()
{
    int nValue = 5;
    float fValue = 7.5;
    char szValue[] = "Mollie";

    printValue(&nValue, INT);
    printValue(&fValue, FLOAT);
    printValue(szValue, CSTRING);
}