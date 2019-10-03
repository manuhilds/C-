#include <iostream>
#include <array>
#include <vector>

int generateID()
{
    static int s_id = 0;
    return ++s_id;
}

class Something
{

  private:
    static int s_idGenerator;
    int m_id;

  public:
    Something() { m_id = s_idGenerator++; } // grab the next value from the id generator
    int getID() const { return m_id; }

    int m_value = 1;
    static int s_value;
    static const int k_s_value = 5;
};
int Something::s_idGenerator = 1;

class Whatever
{
  public:
    static constexpr double s_value = 2.2;                   // ok
    static constexpr std::array<int, 3> s_array = {1, 2, 3}; // this works too
};
int Something::s_value = 1;

class Something1
{
  private:
    static int s_value;

  public:
    static int getValue() { return s_value; }
};
int Something::s_value = 1;

class IDGenerator
{
  private:
    static int s_nextID; // Here's the declaration for a static member

  public:
    static int getNextID(); // Here's the declaration fer a static function
};

int IDGenerator::s_nextID = 1; // definition of the static member variable : no use of static 

int IDGenerator::getNextID(){return s_nextID++;} // definition of the static member function : no use of static 

class MyClass
{
  public:
    static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars = {'a','e','i','o','u'};

class MYClass
{
  private:
    static std::vector<char> s_mmychars;
  public:
    
    class _init // we're defining a nested class named _init
    {
      public:
        _init() // _init constructor will initialize our static variable
        {
          s_mmychars.push_back('a');
          s_mmychars.push_back('e');
          s_mmychars.push_back('i');
          s_mmychars.push_back('o');
          s_mmychars.push_back('u');
        }
    };

    private:
      static _init s_initializer; // we'll use this static object to ensure the _init constructor is callled 
};

std::vector<char> MYClass::s_mmychars;
MYClass::_init MYClass::s_initializer;

int main()
{
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';
    std::cout << generateID() << '\n';

    Something first;
    Something second;

    first.m_value = 2;
    first.s_value = 2;

    std::cout << first.m_value << '\n';
    std::cout << second.m_value << '\n';
    std::cout << first.s_value << '\n';
    std::cout << second.s_value << '\n';

    std::cout << Something1::getValue() << '\n';
    return 0;
}