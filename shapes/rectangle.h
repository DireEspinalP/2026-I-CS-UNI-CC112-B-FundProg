#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "shape.h"

class Rectangle : public Shape {
    Side m_width, m_height;
public:
    Rectangle(Side width, Side height, const string& name = "Rectangle");
    Area GetArea() const override;
};

#endif // __RECTANGLE_H__
