#include <iostream>

class IntArray
{
private:
    int m_array[10];
public:
    void setValue(int index, int value)
    {
        // If the index is invalid, do nothing 
        if (index <0 || index >=10)
            return;
        m_array[index] = value;
    }
};

class Something
{
private:
    int m_value1;
    int m_value2;
    int m_value3;

public:
    void setValue1(int value){m_value1 = value;}
    int getValue1(){ return m_value1;}
};

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;
public:
    int getMonth(){ return m_month;} // getter for month
    void seMonth() { m_month = month;} // setter for month

    int getDay(){return m_day;} // getter for day
    void setDay(){ m_day = day;} // setter for day

    int getYear() { return m_year;  } // getter for year
    void setYear(int year) { m_year = year;} // setter for year
    
};
int main(int argc, char const *argv[])
{
    Something something;
    something.setValue1(5);
    std::cout << something.getValue1() << '\n';
    return 0;
}
