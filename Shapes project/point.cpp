// filename: Point.cpp
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This contains the constructor and the draw function to draw on the grid
#include "point.h"
#include <iostream>
using namespace std;
Point::Point(int x, int y, char c) : Shape(x, y) 
{
        m_c = c;
}
void Point::draw(Grid &grid)
{
       grid.set(m_x,m_y, m_c);
}
