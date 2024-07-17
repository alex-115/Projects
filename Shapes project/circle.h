// filename: Circle.h
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This contains the constructor of circle and a draw function to draw out the circle
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <iostream>
using namespace std;

class Circle : public Shape
{
        public:
        Circle(int m_x,int m_y);
        void draw(Grid &grid);
};
#endif
