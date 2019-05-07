#ifndef EMPTY_SET_H
#define EMPTY_SET_H
#include "object.h"

class EmptySet : public Object
{
public:
    EmptySet()
    {
        vector<Object*> v = {};
        _emptyObj = v;
    }

    void add(Object * obj)
    {
        _emptyObj.push_back(obj);
    }
    string getValueStr()
    {
        return _valueString;
    }
private:
    string _valueString = "{}";
    vector<Object*> _emptyObj;
};

#endif