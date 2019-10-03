#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2d
{
  private:
    int m_x;
    int m_y;

  public:
    Point2d() : m_x(0), m_y(0) {}
    Point2d(int x, int y) : m_x(x), m_y(y) {}

    // An overloaded output operator
    friend std::ostream &operator<<(std::ostream &out, const Point2d &point)
    {
        out << "(" << point.m_x << ", " << point.m_y << ")";
    }
    // Access functions
    void setPoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
};

#endif