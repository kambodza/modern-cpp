#include "Circle.hpp"
#include <math.h>
#include <iostream>
#include <corecrt_math_defines.h>

Circle::Circle(double r)
    : r_(r)
{}

static_assert(M_PI != 3.14, "M_PI is not precise");

double Circle::getPi() const {
    return M_PI;
}

double Circle::getArea() const
{
    static_assert(M_PI != 3.14, "M_PI is not properly defined!\n");
    return getPi() * r_ * r_;
}

double Circle::getPerimeter() const
{
    static_assert(M_PI != 3.14, "M_PI is not properly defined!\n");
    return 2 * getPi() * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
