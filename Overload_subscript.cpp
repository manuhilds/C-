#include <iostream>
#include <assert.h> // for assert()

class IntList
{
private:
  int m_list[10];

public:
  int &operator[](const int index);
  const int &operator[](const int index) const;
};

int &IntList::operator[](const int index) // for non-const objects: can be used for assignment
{
  assert(index >= 0 && index < 10);
  return m_list[index];
}

const int &IntList::operator[](const int index) const // for const objects: can only be used for access
{
  return m_list[index];
}

int main(int argc, char const *argv[])
{
  IntList list;
  list[2] = 3;          // okay: calls non-const version of operator[]
  std::cout << list[2]; // get a value

  const IntList clist;
  clist[2] = 3; // compile error: calls const verision of operator[], which returns a const reference. Cannot assign to this.
  std::cout << clist[2];

  IntList *list1 = new IntList;
  (*list)[2] = 3; // get our IntList object, then call overloaded operator[]
  delete list;

  return 0;
}
