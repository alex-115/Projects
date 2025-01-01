// filename: ADT.h
// Short summary of the file contents: This file is the header of linked lists that will hold the contents of the weather stations in Chico.
#ifndef ADT_H
#define ADT_H
#include "data.h"
#include <iostream>
using namespace std;
    class List
{
        public:
                List();
                ~List();
                int daysaboveonehalf(int total); // function that checks if a day had over 0.5 inches of rain
                void insert(Data *my_data); // function that inserts into a linked list
                bool find(string date); // function that finds a specific date from a linked list and returns false if not found
                void print(); // function that will print data 
                int Length(); // function that checks the length of a linked list
        private:
                class Node{
                        public:
                                Node(Data *mydata, Node *next)
                                {
                                        m_data = mydata;
                                        m_next = next;
                                }
                                Data *m_data;
                                Node *m_next;
                };
                Node *m_head;
};
#endif
