#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square(Side side, const string& name = "Square");
};

#endif // __SQUARE_H__
