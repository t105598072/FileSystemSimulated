#ifndef OBJECT_ITERATOR_H
#define OBJECT_ITERATOR_H
#include <vector>
#include "object.h"

class ObjectIterator
{
public:
    ObjectIterator(Object * obj):_obj(obj){}
    void first()
    {
        //_it = _obj->
    }

    Object * currentItem()
    {

    }

    void next()
    {

    }
    bool isDown()
    {

    }
private:
    Object * _obj;
    std::vector<Object *>::iterator _it;
};

#endif