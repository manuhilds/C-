#include <iostream>

class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }
     // overloaded int cast
     operator int() {return m_cents;}

    int getCents() { return m_cents; }
    int setCents(int cents) { m_cents = cents; }
};

void printInt(int value)
{
    std::cout << value;
}

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0) { m_dollars = dollars;}
    operator Cents() { return Cents(m_dollars * 100);}
};

void printCents( Cents cents)
{
    std::cout << cents; // censt will be implicitly cast to an int here
}

int main(int argc, char const *argv[])
{
    Cents cents(7);
    printInt(cents); // print 7

    Dollars dollars(9);
    printCents(dollars); // dollars will be implicitly cast to a Cents here 
    return 0;
}
