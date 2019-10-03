#include <iostream>

class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents) { m_cents = cents; }

    // add Cents + Cents using a friend function
    friend Cents operator+(const Cents &c1, const Cents &c2);

    // add int to Cents
    friend Cents operator+(const Cents &c1, int value);
    friend Cents operator+(int value, const Cents &c1);

    // subtract Cents - Cents using a friend function
    friend Cents operator-(const Cents &c1, const Cents &c2);

    int getCents() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
    // use the Cents constructor and operator+(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents(c1.m_cents + c2.m_cents);
}

Cents operator+(const Cents &c1, int value)
{
    return Cents(c1.m_cents + value);
}

Cents operator+(int value, const Cents &c1)
{
    return Cents(c1.m_cents + value);
}

// note: this function is not a member function!
Cents operator-(const Cents &c1, const Cents &c2)
{
    // use the Cents constructor and operator-(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents(c1.m_cents - c2.m_cents);
}

class MinMax
{
  private:
    int m_min; // The min value seen so far
    int m_max; // The max value seen so far
  public:
    MinMax(int min, int max) : m_min(min), m_max(max) {}
    int getMin() { return m_min; }
    int getMax() { return m_max; }

    friend MinMax operator+(const MinMax &m1, const MinMax &m2);
    friend MinMax operator+(const MinMax &m, int value);
    friend MinMax operator+(int value, const MinMax &m);
};

MinMax operator+(const MinMax &m1, const MinMax &m2)
{
    // Get the minimum value seen in m1 and m2
    int min = m1.m_min < m2.m_min ? m1.m_min : m2.m_min;

    // Get the maximum value seen in m1 and m2
    int max = m1.m_max > m2.m_max ? m1.m_max : m2.m_max;

    return MinMax(min, max);
}

MinMax operator+(const MinMax &m, int value)
{
    // Get the minimum value seen in m and value
    int min = m.m_min < value ? m.m_min : value;

    // Get the maximum value seen in m and value
    int max = m.m_max > value ? m.m_max : value;

    return MinMax(min, max);
}

MinMax operator+(int value, const MinMax &m1)
{
    //call operator+(MinMax, int)
    return m1 + value;
}

int main(int argc, char const *argv[])
{
    Cents cents1(6), cents2(8);
    Cents centsSum = cents1 + cents2;
    Cents centsSub = cents1 - cents2;
    std::cout << "I have " << centsSum.getCents() << " cents." << std::endl;

    Cents c1 = Cents(4) + 6;
    Cents c2 = 6 + Cents(4);

    std::cout << "I have " << c1.getCents() << " cents." << std::endl;
    std::cout << "I have " << c2.getCents() << " cents." << std::endl;

    MinMax m1(10, 15);
    MinMax m2(8, 11);
    MinMax m3(3, 12);
    MinMax mFinal = m1 + m2 + 5 + 8 + m3 + 16;
    std::cout << "Result: (" << mFinal.getMin() <<", "<< mFinal.getMax() << ")\n";

    return 0;
}
