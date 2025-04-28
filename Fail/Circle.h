#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(float r);
    ~Circle();
    float Area();
    void SetRadius(float radius);
    float GetRadius();
private:
    float m_radius;
};

#endif
