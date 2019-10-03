#include <iostream>
#include <cassert>
#include <string>   

class Matrix
{
  private:
    double data[4][4];

  public:
    Matrix(/* args */)
    {
        // Set all elements of the matrix to 0.0
        for (int row = 0; row < 4; ++row)
            for (int col = 0; col < 4; ++col)
                data[row][col] = 0.0;
    }

    double &operator()(int row, int col);
    const double &operator()(int row, int col) const; // for const objects
    void operator()();
};

double &Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return data[row][col];
}

void Matrix::operator()() 
{
    // reset all elements of the matrix to 0.0
    for (int row=0;row <4; ++row)
        for (int col=0;col <4; ++col)
            data[row][col] = 0.0;
}


class Accumulator
{
private:
    int m_counter = 0;
public:
    Accumulator() { }
    int operator() (int i) { return (m_counter += i);}
};


class Mystring
{
private:
    std::string m_string;
public:
    Mystring(const std::string string=""): m_string(string) { }
    std::string operator() (int start, int length)
    {
        assert(start+ length <= m_string.length() && "Mystring::operator(int, int): Substring is out of range");
        std::string ret;
        for (int count=0;count < length;++ count)
            ret += m_string[start + count];
        return ret;
    }
};









int main(int argc, char const *argv[])
{
    Matrix matrix;
    matrix(1,2) = 4.5;
    matrix();
    std::cout << matrix(1,2);


    Accumulator acc;
    std::cout << acc(10) << std::endl; // prints 10
    std::cout << acc(20) << std::endl; // prints 30

    Mystring string("Hello, world!");
    std::cout << string(7,5); // start at index 7 and returns 5 characters

    return 0;
}
