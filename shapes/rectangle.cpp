#include "rectangle.h"

Rectangle::Rectangle(Side width, Side height, const string& name)
    : Shape(name), m_width(width), m_height(height) {}

Area Rectangle::GetArea() const { return m_width * m_height; }
