// ovperator overloading, overloaded typecasts, copy constructor

/* operator overloading -> normal, friend, member functions:
    - member function: (=),([]), (()), (->), unary operator(-,+), binary functions that only modifies its left operand
    - friend function: binary operator that does not modify its left operand (+), cout
    - normal function: // -cout

*/

#include <iostream>
#include <cassert>

class Average
{
  private:
    int32_t sum =0;
    int8_t count=0;

  public:
    Average(/* args */) {}
    Average &operator+=(int num)
    {
        sum += num;
        ++count;
    }
    friend std::ostream& operator<<(std::ostream& out, const Average &average)
    {
        out <<static_cast<double>(average.sum)/average.count;
        return out;
    }
    ~Average() {}
};

int main()
{
    Average avg;

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10;         // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy = avg;
    std::cout << copy << '\n';

    return 0;
}