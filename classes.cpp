#include <iostream>
#include <string>

// struct
struct DateStruct
{
    int year;
    int month;
    int day;
};

// class
class DateClass
{
    int m_year;
    int m_month;
    int m_day;

public:
    void setDate(int month, int day, int year)
    {
        // setDate can access the private members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }
    void print() // defines a member function named print()
    {
        std::cout << m_year << "/" << m_month << "/" << m_day;
    }
    void copyFrom(const DateClass &d)
    {
        // Note that we can access the private members of d directly 
        m_month = d.m_month;
        m_day = d.m_day;
        m_year = d.m_year;
    }
};

class Employee
{
  public:
    std::string m_name;
    int m_id;
    double m_wage;

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name << " Id: " << m_id << " Wage: $" << m_wage << '\n';
    }
};

void print(DateStruct &date)
{
    std::cout << date.year << "/" << date.month << "/" << date.day;
}

int main()
{
    DateStruct today{2020, 10, 14}; // use uniform initialization
    DateClass tomorrow;



    today.day = 16; // use member selection operator to select a member of the struct
    tomorrow.setDate(12,16,2015);
    tomorrow.print();

    DateClass copy;
    copy.copyFrom(tomorrow);
    copy.print();

    print(today);

    // declare two employees
    Employee alex {"Alex",1,25.00};
    Employee joe {"Joe",2,22.25};

    // Print out the employee information
    alex.print();
    joe.print();

    return 0;
}