#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <map>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;





void printCollectionElements(const Collection& collection)
{
    for(auto& el : collection)
        if(el) {
            el->print();
        }
}

void printAreas(const Collection& collection)
{
    for(auto& el : collection)
        if(el) {
            cout << el->getArea() << std::endl;
        }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibonacci(int n)
{
    if(n <= 2 ){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // int result = fibonacci(100);
    // cout << result << "\n";

    cout << alignof(Circle) << "\n";

    Collection shapes = {
    make_shared<Circle>(2.0),
    make_shared<Circle>(3.0),
    nullptr,
    make_shared<Circle>(4.0),
    make_shared<Rectangle>(10.0, 5.0),
    make_shared<Square>(3.0),
    make_shared<Circle>(4.0),
    };

    shapes.push_back(make_shared<Circle>(Color::Black));
    
    printCollectionElements(shapes);

    std::map<shared_ptr<Shape>, double> perimeters;
    std::transform(shapes.begin(),
                   shapes.end(),
                   inserter(perimeters, perimeters.begin()),
                   [](auto& shape){ 
                    auto perimeter = 0.0;
                    if(shape){
                        perimeter = shape->getPerimeter();
                    }
                    return make_pair(shape, perimeter); 
                   });
    for(auto && [key, value] : perimeters){
        if(key){
            key->print();
            cout << value << "\n";
        }
    }
    
    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    };

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);


    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };

    auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getArea() < x);
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}

