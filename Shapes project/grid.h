// filename: Grid.h
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This contains the constructor, the void set function, and print function.
#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

class Grid
{
    public:
            Grid();
            void set(int x, int y, char c); 
            void print();
    private:
            int grid_x;
            int grid_y;
            char grid_c;
            char grid[24][60];
};
#endif
