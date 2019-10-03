#include <iostream>
#include <cassert>

class Foo
{
  public:
    int m_x;
    int m_y;
};

class Fraction
{
  private:
    int m_numerator;
    int m_denominator;

  public:
    // default constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Something
{

  public:
    //  Default constructor
    Something(int n = 0, double d = 1.2) // allows us to construct a Something(int,double), Something(int), or Something()
    {
    }
    Something(double d)
    {

    }
};


class A
{
public:
    A() { std::cout <<"A\n";}
};

class B
{
private:
    A m_a; // B contains A as a member variable
public:
    B() { std::cout << "B\n";}
};


int main(int argc, char const *argv[])
{
    Foo foo1 = {4, 5}; // initialization list
    Foo foo2{6, 7};    // uniform initialization

    Fraction frac; // Since no arguments, calls Fraction() default constructor
    std::cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';

    Fraction fiveThirds{5, 3};
    Fraction six(6);

    Something s1{1, 2.4};
    Something s2{1};
    Something s3; // calls Something(int, double)
    Something s4{2.4};


    B b; 
    return 0;
}
