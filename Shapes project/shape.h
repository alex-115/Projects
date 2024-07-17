// filename: Shape.h
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This contains the base class shape that has a constructor and a virutal draw function 
#ifndef SHAPE_H
#define SHAPE_H
#include "grid.h"
#include <iostream>
using namespace std;

class Shape
{
        public:
                Shape(int x, int y);
                virtual void draw(Grid &grid) = 0; // not sure if this needs to be in shape.cpp
        protected:
                int m_x;
                int m_y;
};
#endif 
