//filename: Dstack.h
//Name: Alejandro Barajas
//INGinious username: ajbarajas1
//Summary:This is the header file of the program that contains the contents of stacks and in this case is required to store the inputs of the user.
#ifndef MY_DSTACK_H
#define MY_DSTACK_H
#include <iostream>
using namespace std;
    class Dstack
{
        public:
                Dstack();
                ~Dstack();
                void push(double value);
                bool pop(double &value);
                int size();
                bool empty();
        private:
                class Node 
                {
                        public:
                                Node(double value, Node *next)
                                {m_value = value; m_next = next;}
                                double m_value;
                                Node *m_next;
                };
                Node *m_top;
};
#endif
