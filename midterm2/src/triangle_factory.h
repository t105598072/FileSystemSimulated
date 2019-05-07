#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H
#include "shape.h"
#include "triangle.h"

class TriangleFactory{
public:
    TriangleFactory() : _triangle(nullptr)
    {
    }

    Shape * create(int a, int b, int c)
    {
        if(a<=0||b<=0||c<=0||a+b<=c||b+c<=a||a+c<=b)
            return _triangle;
        else
        {
            Triangle * triangle = new Triangle(a, b, c);
            _triangle = triangle;
        }
        return _triangle;
    }
private:
    Shape * _triangle;
    bool _exceptinoChecker;
};

#endif