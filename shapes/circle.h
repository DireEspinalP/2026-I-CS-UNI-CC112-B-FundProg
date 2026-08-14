#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "shape.h"

class Circle : public Shape {
    Side m_x, m_y, m_r;
public:
    Circle(Side x, Side y, Side r, const string& name = "Circle");
    Area GetArea() const override;
    Side GetX() const { return m_x; }
    Side GetY() const { return m_y; }
};

#endif // __CIRCLE_H__
