#include "Circle.hpp"
#include <math.h>
#include <iostream>
#include <numbers>


std::ostream& operator<<(std::ostream & os, Color c){
    if(c == Color::White){
        os << "White";
    }
    else if(c == Color::Black){
        os << "Black";
    }
    else {
        os << "Blue";
    }

    return os;
}

Circle::Circle(double r)
    : r_(r)
{}

Circle::Circle(const Circle& other) : Shape(other)
{
    r_ = other.getRadius();
}

static_assert(std::numbers::pi != 3.14, "M_PI is not precise");

double Circle::getPi() const {
    return std::numbers::pi;
}

double Circle::getArea() const
{
    static_assert(std::numbers::pi != 3.14, "M_PI is not properly defined!\n");
    return getPi() * r_ * r_;
}

double Circle::getPerimeter() const
{
    static_assert(std::numbers::pi != 3.14, "M_PI is not properly defined!\n");
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
