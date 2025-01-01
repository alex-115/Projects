// filename: Triangle.cpp
// Short summary of the file contents: This file builds the triangle shape
#include "triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(int x, int y) : Shape(x,y) {}
void Triangle::draw(Grid &grid)
{
    int cur_x = m_x + 5;
    int cur_y = m_y + 3;
    for( int i = m_x; i < cur_x; i++)
    {
            cur_y = m_y + 2;
            grid.set(i,cur_y, '+');
    }
    grid.set(m_x + 2, m_y, '+');
    grid.set(m_x + 1, m_y + 1, '+');
    grid.set(m_x + 3, m_y + 1, '+');
}

