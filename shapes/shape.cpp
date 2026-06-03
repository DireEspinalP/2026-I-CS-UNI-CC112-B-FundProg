#include "shape.h"

Shape::Shape(const string& name) : m_name(name) {}
Shape::~Shape() = default;
string Shape::GetName() const { return m_name; }
