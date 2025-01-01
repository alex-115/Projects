// filename:Square.cpp
// Short summary of the file contents: This file executes the functions to create and draw out the square
#include "square.h"
#include <iostream>
using namespace std;
Square::Square(int x, int y, int size) : Shape(x,y)
{
        m_size = size;
}
void Square::draw(Grid &grid)
{
        int cur_y = m_y + m_size;
        int cur_x = m_x + m_size;
        for (int i = m_y; i < cur_y; i++)
        {
                for (int j = m_x; j < cur_x; j++)
                {
                        if ( i == m_y || i == cur_y - 1) // first and last row
                        {
                                grid.set(j,i,'*');
                        }
                        if ( j == m_x || j == cur_x - 1) // first and last column
                        {
                                //grid[i][j] = '*';
                                grid.set(j,i,'*');
                        }
                        //else 
                       // {
                        //        grid.set(j,i,' ');
                       // }
                }
        }
}


