#ifndef NUMBER_H
#define NUMBER_H
#include <vector>
#include "object.h"

class Number : public Object
{
public:
   Number(int num):_value(num), _valueStr(to_string(num))
   {
   }

   int getValue()
   {
        return _value;
   }

   string getValueStr()
   {
        return _valueStr;
   }
private:
    vector<Object*> objSet;
    string _valueStr;
    int _value;
};

#endif