#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
  private:
    std::string m_make;
    std::string m_model;

  public:
    Car(std::string make, std::string model) : m_make(make), m_model(model)
    {
    }
    friend bool operator==(const Car &c1, const Car &c2);
    friend bool operator!=(const Car &c1, const Car &c2);
    friend bool operator<(const Car &c1, const Car &c2);
    friend std::ostream &operator<<(std::ostream &out, const Car &car);
};

bool operator==(const Car &c1, const Car &c2)
{
    return (c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!=(const Car &c1, const Car &c2)
{
    return !(c1 == c2);
}

bool operator<(const Car &c1, const Car &c2)
{
    return (c1.m_make == c2.m_make) ? c1.m_make < c2.m_make : c1.m_model < c2.m_model;
}

std::ostream &operator<<(std::ostream &out, const Car &car)
{
    out << "(" << car.m_make << ", " << car.m_model << ")";
    return out;
}
class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents) { m_cents = cents; }

    friend bool operator>(const Cents &c1, const Cents &c2);
    friend bool operator<(const Cents &c1, const Cents &c2);
    friend bool operator<=(const Cents &c1, const Cents &c2);
    friend bool operator>=(const Cents &c1, const Cents &c2);
};

bool operator>(const Cents &c1, const Cents &c2)
{
    return c1.m_cents > c2.m_cents;
}
bool operator>=(const Cents &c1, const Cents &c2)
{
    return c1.m_cents >= c2.m_cents;
}
bool operator<(const Cents &c1, const Cents &c2)
{
    return !(c1 >= c2);
}
bool operator<=(const Cents &c1, const Cents &c2)
{
    return !(c1 > c2);
}

int main(int argc, char const *argv[])
{
    Car corolla("Toyota", "Corolla");
    Car camry("Toyota", "Camry");

    if (corolla == camry)
        std::cout << "a Corolla and Camry are the same.\n";
    if (corolla != camry)
        std::cout << "a Corolla and Camry are not the same.\n";

    Cents dime(10);
    Cents nickel(5);

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";
    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";
    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";
    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";

    std::vector<Car> v;
    v.push_back(Car("Toyota", "Corolla"));
    v.push_back(Car("Honda", "Accord"));
    v.push_back(Car("Toyota", "Camry"));
    v.push_back(Car("Honda", "Civic"));

    std::sort(v.begin(), v.end()); // requires an overloaded operator<

    for (auto &car : v)
        std::cout << car << '\n'; // requires an overloaded operator<<

    return 0;

    return 0;
}
