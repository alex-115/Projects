//filename: Dstack.cpp
//Name: Alejandro Barajas
//INGinious username: ajbarajas1
//Summary: This file has all the required operations that form stacks and executes the functions to create stacks.
#include <iostream>
#include "dstack.h"
using namespace std;
Dstack::Dstack()
{
        m_top = NULL;
}
Dstack::~Dstack()
{
        Node *ptr = m_top;
        while ( ptr != NULL)
        {
                Node *tmp;
                tmp = ptr;
                ptr = ptr->m_next;
                delete tmp;
        }
}
void Dstack::push(double value)
{
        m_top = new Node(value,m_top);
}
bool Dstack::pop(double &value)
{
        if (m_top != NULL)
        {
                Node *tmp;
                tmp = m_top;
                m_top = m_top->m_next;
                value = tmp->m_value;
                delete tmp;
                return true;
        }
        return false;
}
int Dstack::size()
{
        int count = 0;
        Node *ptr = m_top;
        while (ptr != NULL)
        {
                count++;
                ptr = ptr->m_next;
        }
        return count;
}
bool Dstack::empty()
{
        bool empt = true;
        Node *ptr = m_top;
        while ( ptr != NULL)
        {
                empt = false;
        }
        return empt;
}

