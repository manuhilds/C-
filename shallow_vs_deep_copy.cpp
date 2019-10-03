#include <cassert>
#include <iostream>
#include <cstring>

class MyString
{
  private:
    char *m_data;
    int m_length;

  public:
    MyString(const char *source = "")
    {
        assert(source); // make sure source isn't a null string
        // find the length of the string
        // plus on character for a terminator
        m_length = std::strlen(source) + 1;

        // allocate a buffer equal to this length
        m_data = new char[m_length];

        // copy the parameter string into our internal buffer
        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];

        // make sure the string is terminated
        m_data[m_length - 1] = '\0';
    }
    ~MyString()
    {
        // we need to deallocate our string
        delete[] m_data;
    }
    MyString(const MyString &source);
    MyString &operator=(const MyString &source);

    char *getString() { return m_data; }
    int getLength() { return m_length; }
};

// copy constructor
MyString::MyString(const MyString &source)
{
    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;

    // m_data is a pointer, so we need to deep copy it if it's non-null
    if (source.m_data)
    {
        // allocate memory for our copy
        m_data = new char[m_length];

        // do the copy
        for (int i = 0; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = 0;
}

// assignment operator
MyString &MyString::operator=(const MyString &source)
{
    // check for self-assignemnt;
    if (this == &source)
        return *this;

    // first we need to deallocate any value that this string is holding!
    delete[] m_data;

    m_length = source.m_length;

    if (source.m_data)
    {
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
        {
            m_data[i] = source.m_data[i];
        }
    }
    else
    {
        m_data = 0;
    }
    return *this;
}