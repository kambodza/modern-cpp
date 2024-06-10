#pragma once
#include "color.hpp"
class Shape
{
private:
Color color = Color::Black;
public:
    Shape(Color c) : color(c) {}
    Shape() {}
    Shape(Shape const & sh) : color(sh.color) {};
    virtual ~Shape() {}
    

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
