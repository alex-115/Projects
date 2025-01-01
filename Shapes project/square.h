// filename:Square.h
// Short summary of the file contents: This file contains the functions to create and draw the square
#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include <iostream>
using namespace std;
class Square : public Shape
{
        public:
                Square(int m_x, int m_y, int size); // creates the square depending on size
                void draw(Grid &grid); // implements the constructor and draws the square on the grid
        protected:
                int m_size;
};
#endif
