#include <iostream>

class Digit
{
  private:
    int m_digit;

  public:
    Digit(int digit = 0) : m_digit(digit)
    {
    }
    Digit &operator++(); // prefix
    Digit &operator--(); // prefix

    // Note: use of a "dummy variable,dummy argument"
    Digit operator++(int); // postfix
    Digit operator--(int); // postfix
    friend std::ostream &operator<<(std::ostream &out, const Digit &d);
};

Digit &Digit::operator++()
{
    // If our number is already at 9, wrap around to 0;
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;
    return *this;
}

Digit &Digit::operator--()
{
    // If our number is already at 0, wrap around to 0
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;
    return *this;
}

Digit Digit::operator++(int)
{
    // Create a temporary variable with our current digit
    Digit temp(m_digit);

    // Use prefix operator to increment this digit
    ++(*this);   // apply operator
    return temp; // return saved state
}

Digit Digit::operator--(int)
{
    // Create a temporary variable with our current digit
    Digit temp(m_digit);

    // Use prefix operator to decrement this digti
    --(*this); // apply operator
    return temp; // return save state.
}

std::ostream &operator<<(std::ostream &out, const Digit &d)
{
    out << d.m_digit;
    return out;
}

int main(int argc, char const *argv[])
{
    Digit digit(8);

    std::cout << digit;
    std::cout << ++digit; // Digit::operator++()
    std::cout << digit++; // Digit::operator++(int)
    std::cout << --digit; // Digit::operator--()
    std::cout << digit--; // Digit::operator--(int)

    return 0;
}
