#include <cassert>
#include <iostream>
#include <string>

class Fraction
{
  private:
    int m_numerator;
    int m_denominator;

  public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

    // Copy constructor
    Fraction(const Fraction &copy) : m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
    {
        // no need to check for a denominator of 0
        std::cout << "Copy constructor called\n";
    }

    // Overloaded assignement
    Fraction &operator=(const Fraction &fraction);
    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
};

std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fraction &Fraction::operator=(const Fraction &fraction)
{
    // self-assignement guard
    if (this == &fraction)
        return *this;
    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}

class MyString
{
  private:
    char *m_data;
    int m_length;

  public:
    MyString(const char *data = "", int length = 0) : m_length(length)
    {
        if (!length)
            m_data = nullptr;
        else
            m_data = new char[length];
        for (int i = 0; i < length; ++i)
            m_data[i] = data[i];
    }

    // Overloaded assignement
    MyString &operator=(const MyString &str);
    friend std::ostream &operator<<(std::ostream &out, const MyString &s);
};

std::ostream &operator<<(std::ostream &out, const MyString &s)
{
    out << s.m_data;
    return out;
}

MyString &MyString::operator=(const MyString &str)
{
    // if data exists in the current string, delete it
    if (m_data)
        delete[] m_data;

    m_length = str.m_length;

    //copy the data from str to the implicit object
    m_data = new char[str.m_length];

    for (int i = 0; i < str.m_length; ++i)
        m_data[i] = str.m_data[i];

    // return the existing object so we can chain this operator
    return *this;
}

int main()
{

    Fraction fiveThirds(5, 3);
    Fraction f;
    f = fiveThirds; // calls overloaded assignement
    std::cout << f;

    MyString alex("Alex", 5); // Meet Alex
    MyString employe;
    employe = alex; // alex is our newest employe
    std::cout << employe;

    return 0;
}