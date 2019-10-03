#include <iostream>


// using friend functions:
// gives acces to member of the class

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents) { m_cents = cents;}
    int getCents() const { return m_cents;}

    friend Cents operator+(const Cents &c1, const Cents &c2);

};


Cents operator+(const Cents &c1, const Cents &c2)
{
    return Cents(c1.m_cents+ c2.m_cents);
}

// using normal functions:
// if you don't need access to member of the class 
Cents operator+(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents()+c2.getCents());
}

// using member functions:
class Cents_mem
{
private:
    int m_cents;
public:
    Cents_mem(int cents) { m_cents = cents;}
    
    Cents_mem operator+(int value);
    int getCents(){return m_cents;}
};

Cents_mem Cents_mem::operator+(int value)
{
    return Cents_mem(m_cents + value);
}