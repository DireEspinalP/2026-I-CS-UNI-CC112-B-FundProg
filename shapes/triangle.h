#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "shape.h"

class Triangle : public Shape {
    Side m_base, m_height;
public:
    Triangle(Side base, Side height, const string& name = "Triangle");
    Area GetArea() const override;
};
///
#endif // __TRIANGLE_H__
