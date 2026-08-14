#include "triangle.h"

Triangle::Triangle(Side base, Side height, const string& name)
    : Shape(name), m_base(base), m_height(height) {}

Area Triangle::GetArea() const { return 0.5 * m_base * m_height; }
