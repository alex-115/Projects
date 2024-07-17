// filename: Circle.cpp
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This file contains the functions of creating the circle and drawing it out based on the x and y input
#include "circle.h"
#include <iostream>
using namespace std;
Circle::Circle(int x, int y) : Shape(x,y) {}
void Circle::draw(Grid &grid)
{
   //int m_y = 0, m_x = 0;
   int cur_y = m_y + 4;
   int cur_x = m_x + 4;
   for (int i = 0; i < cur_y; i++)
   {
           if ( i == m_y || i == cur_y - 1) // first and last row
           {
                   //grid[i][m_x + 1] = 'o';
                   grid.set(m_x + 1, i, 'o');
                   //grid[i][m_x + 2] = 'o';
                   grid.set(m_x+2, i, 'o');
           }
           if ( i == m_y + 1 || i == m_y + 2) // first and last column
           {
                   //grid[i][m_x] = 'o';
                   grid.set(m_x, i,'o');
                   //grid[i][cur_x - 1] = 'o';
                   grid.set(cur_x - 1,i,'o');
           }
   }

}
