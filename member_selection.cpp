#include <iostream>

struct Person
{
    int age;
    double weight;
};

Person person;

int main()
{
    // member selection using actual struct variable
    person.age = 5;

    // member selection using reference to struct
    Person &ref = person;
    ref.age = 5;

    //member selection using pointer to struct
    Person *ptr = &person;
    (*ptr).age = 5;//same effect
    ptr->age = 5;
    return 0;
}
