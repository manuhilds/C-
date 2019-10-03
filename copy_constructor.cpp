#include <cassert>
#include <iostream>

class Fraction
{
  private:
    int m_numerator;
    int m_denominator;

    // copy constructor
    Fraction(const Fraction &fraction) : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    // Note: we can access the members of parameter fraction directly, because we're inside the Fraction class
    {
        // no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

  public:
    // default constructor
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
};

std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

int main(int argc, char const *argv[])
{
    Fraction fiveThirds(5, 3);  // Direct initialize a Fraction, calls Fraction(int, int) constructor
    Fraction fCopy(fiveThirds); // Direct initialize -- with Fraction copy constructor
    std::cout << fCopy << '\n';
    return 0;
}
