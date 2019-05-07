#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include <string>

using namespace std;
class Triangle : public Shape
{
public:
    Triangle(int a, int b, int c):_sideA(a),_sideB(b),_sideC(c)
    {
        if(_sideA<=0||_sideB<=0||_sideC<=0||_sideA+_sideB<=_sideC||_sideB+_sideC<=_sideA||_sideA+_sideC<=_sideB){
            throw string("illegal triangle");
            _isCreate = false;
        }
        else
            _isCreate = true;
    }

    bool isCreate()
    {
        return _isCreate;
    }

    int perimeter() const
    {
        return _sideA+_sideB+_sideC;
    }

    ~Triangle();

private:
    int _sideA;
    int _sideB;
    int _sideC;
    bool _isCreate;
};

#endif