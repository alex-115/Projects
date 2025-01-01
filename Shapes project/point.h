// filename: Point.h
// Short summary of the file contents: This contains the constructor of point and the function to draw the point
#ifndef POINT_H
#define POINT_H
#include "shape.h"
#include <iostream>
using namespace std;

class Point : public Shape
{
        public:
        Point(int m_x, int m_y, char c);
        void draw(Grid &grid);
        protected:
        char m_c;
};

#endif

