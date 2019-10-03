#include <iostream>
#include <string>
#include <vector>

// map : class that stores elements as a key-pair.
// app that assign grades to students by name using a map class
// key: student's name, value: grade

struct StudentGrade
{
    std::string name;
    char grade;
};

class GradeMap
{
  private:
    std::vector<StudentGrade> m_map;

  public:
    GradeMap() {}
    char &operator[](std::string parameter);
};

char &GradeMap::operator[](std::string name)
{
    // See if we can find the name in the vector
    for (auto &ref : m_map)
    {
        // If we found the name in the vector, return the grade
        if (ref.name == name)
            return ref.grade;
    }
    StudentGrade temp{name, ' '};
    m_map.push_back(temp);
    return m_map.back().grade;
}
int main(int argc, char const *argv[])
{
    GradeMap grades;
    grades["Joe"] = 'A';
    grades["Franke"] = 'B';
    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
    return 0;
}
