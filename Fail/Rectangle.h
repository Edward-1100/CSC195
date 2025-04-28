#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(float w, float h);
    ~Rectangle();
    float Area();
private:
    float m_width;
    float m_height;
};

#endif
