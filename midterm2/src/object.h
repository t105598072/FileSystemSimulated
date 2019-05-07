#ifndef OBJECT_H
#define OBJECT_H
#include <vector>

using namespace std;
class Object
{
public:
    Object()
    {
    }

    virtual void add(Object * obj)
    {
        throw string("can't apply");
    }

    virtual string getValueStr()
    {
        throw string("can't apply");
    }

private:
vector<Object*>_objSet;
};


#endif