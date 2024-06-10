#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

    virtual double getX() const final;
    double getY() const;

private:
    double x_;
    double y_;
};
