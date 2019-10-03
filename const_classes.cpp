#include <iostream>

class Something
{

  public:
    int m_value;
    Something() : m_value(0) {}

    void resetValue() { m_value = 0; }
    void setValue(int value) { m_value = value; }

    int getValue() const;
};

int Something::getValue() const
{
    return m_value;
}

class Date
{
  private:
    int m_year;
    int m_month;
    int m_day;

  public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    // setDate() cannot be const, modifies member variables
    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
    void printDate(const Date &date);
};

void Date::printDate(const Date &date)
{
    std::cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << '\n';
}
int main(int argc, char const *argv[])
{
    Date date(2016, 10, 16);
    printDate(date);

    return 0;
}
