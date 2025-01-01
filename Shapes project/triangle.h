// filename: Triangle.h
// Short summary of the file contents: This file contains the contents of the triangle header file which is also a derived class of shape
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
using namespace std;
class Triangle : public Shape
{
        public:
                Triangle(int m_x, int m_y); // maybe m_x
                void draw(Grid &grid);
};
#endif
