#include "circle.h"
#include <numbers>

Circle::Circle(Side x, Side y, Side r, const string& name)
    : Shape(name), m_x(x), m_y(y), m_r(r) {}

Area Circle::GetArea() const { return numbers::pi * m_r * m_r; }
