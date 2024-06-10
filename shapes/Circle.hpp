#pragma once

#include "Shape.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream & os, Color c);

class alignas(128) Circle final : public Shape
{
public:
    using Shape::Shape;
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other);

    double getPi() const;
    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

    double getRadius() const;
private:
    double r_ = 1.0;
};
