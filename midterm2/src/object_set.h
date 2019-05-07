#ifndef OBJECT_SET_H
#define OBJECT_SET_H
#include "object.h"
#include "object_iterator.h"

class OjectSet : public Object
{
public:
    OjectSet()
    {
    }

    void add(Object * obj)
    {
        _objectSetVector.push_back(obj);
    }

    string getValueStr()
    {
        return "";
    }

    ObjectIterator * createIterator()
    {
        return new ObjectIterator(this);
    }
protected:
    vector<Object*> _objectSetVector;
};

#endif