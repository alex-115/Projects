// filename: Triangle.h
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This file contains the contents of the triangle header file that is also a derived class of shape
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
