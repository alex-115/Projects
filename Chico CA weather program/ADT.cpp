// filename: ADT.cpp
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This file contains the functions of the ADT.h file. Each function has different commands for the linked list. 
#include "ADT.h"
#include "data.h"
#include <iostream>
using namespace std;
List::List()
{
        m_head = NULL;
}
List::~List()
{
        while(m_head)
        {
                Node *tmp = m_head;
                m_head = m_head->m_next;
                delete tmp;
        }
}
void List::insert(Data *my_data)
{
        Node *tmp = new Node(my_data,NULL);
        if (m_head == NULL)
        {
                m_head = tmp;
                return;
        }
        Node *ptr = m_head;
        while (ptr->m_next != NULL) // Insert at the end of each list
        {
                ptr = ptr->m_next;
        }
        ptr->m_next = tmp;
}
int List::daysaboveonehalf(int total_days) // counts the total of days where rain is above 0.5 inches
{
        if (total_days > 0.5)
        {
                 return 1;
        }
        else if (total_days < 0.5)
        {
                return 0;
        }
        return total_days;
}

void List::print()
{
        Node *ptr = m_head;
        while (ptr->m_next != NULL)
       {
                ptr = ptr->m_next;
                ptr->m_data->print();
       }
}
bool List::find(string date) //funcion to find a date 
{
        Node *ptr = m_head;
        while ( ptr != NULL)
        {
                if (ptr->m_data->GetDate() == date)
                {
                        return true;
                }      
                ptr = ptr->m_next;
        }
        return false;

}
int List::Length() // function to check lenght of a linked list
{
        int count = 0;
        Node *ptr = m_head;
        while (ptr != NULL)
        {
                ptr = ptr->m_next;
                count++;
        }
        return count;
}




