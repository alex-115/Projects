// filename: Grid.cpp
// Short summary of the file contents: This executes the constructor, void set function, and print function.
#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid()
{
    const int num_c = 60, num_r = 24;
    for (int i = 0; i < num_r; i++)
    {
            for(int j = 0; j < num_c;j++)
            {
            grid[i][j] = ' ';
            }
    }

}
void Grid::set(int x, int y, char c)
{  
        if (x >= 0 && x < 60 && y >= 0 && y < 24)
        {
        grid[y][x] = c;
        }
       
}
void Grid::print()
{
        int num_r = 24;
        int num_c = 60;
       for (int i = 0; i < num_r; i++)
    {
            for(int j = 0; j < num_c;j++)
            {
             cout << grid[i][j];
            }
            cout << endl;
    }
}

