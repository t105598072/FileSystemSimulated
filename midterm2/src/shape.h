#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    virtual bool isCreate()
    {
        throw std::string("can't apply");
    }
    virtual int perimeter() const
    {
        throw std::string("can't apply");
    }

};

#endif