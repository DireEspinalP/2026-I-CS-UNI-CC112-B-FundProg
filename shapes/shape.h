#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>
using namespace std;

using Area = double;
using Side = double;

class Shape {
    string m_name;
public:
    Shape(const string& name);
    virtual ~Shape();
    virtual string GetName() const;
    virtual Area   GetArea() const = 0;
};

#endif // __SHAPE_H__
