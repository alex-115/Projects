// filename: BST.cpp
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This file contains the functions of a BST and how they work. There are helpful comments throughout this file that are hints at what is going on within each function.
#include <queue>
#include <vector>
#include "bst.h"
#include <iostream>
using namespace std;
BST::BST()
{
   m_root = NULL;
}
void BST::DeletePostOrder(TreeNode *cur_root) // in bst.h deconstructor calls this func
{
        if (cur_root == NULL)
        {
                return;
        }
        DeletePostOrder(cur_root->m_left);
        DeletePostOrder(cur_root->m_right);
        delete cur_root;
}
bool BST::insert(string str, TreeNode *&cur_root) // in bst.h insert(string str) returns this func
{ 
        if ( cur_root == NULL)  
      {
              cur_root = new TreeNode(str);
              count++; // int value from bst.h file
              return true;
      }
        else if ( cur_root->m_value == str)  // else if key already exist in tree
        {               
                return false;
        }
        else if (cur_root->m_value > str) // recursively insert in left
        {
                return insert(str,cur_root->m_left);

        }
        else {
                return insert(str,cur_root->m_right); // recursviely insert in right
             }
    }
int BST::size()
{
        return count;
}
bool BST::find(string str,TreeNode *&cur_root) // in bst.h find(string str) returns this func
{
        if (cur_root == NULL) // iterated through tree and str was not found
        {
                return false;
        }
        if ( str == cur_root->m_value)
        {
                return true;
        }
        else if ( str < cur_root->m_value)
        {
                return find(str,cur_root->m_left);
        } 
        else
        {
                return find(str,cur_root->m_right);
        }
}
void BST::print(vector<string> &myvec, TreeNode *&cur_root, int count2) // in bst.h print(myvec) returns this func
{
        if (cur_root == NULL) 
        { 
                return; 
        }
        // in order traversal
        if (cur_root != NULL)
        {
                print(myvec, cur_root->m_left, count2); // vist left subtree
                myvec.push_back(cur_root->m_value); // store value in vector
                count2++; // increment
                print(myvec,cur_root->m_right,count2); // visit right subtree
        }
}
void BST::breadth(vector<string> &myvec) // no private helper func
{
        TreeNode *tmp;
        queue<TreeNode*> q;
        q.push(m_root);
        while ( !q.empty())
        {
                tmp = q.front();
                q.pop();
                if (tmp != NULL)
                {
                myvec.push_back(tmp->m_value);
                if (tmp->m_left != NULL)
                    {
                        q.push(tmp->m_left); 
                    }
                if (tmp->m_right != NULL)
                    {
                        q.push(tmp->m_right);
                    }
                }
        }

}
double BST::distance(TreeNode *&cur_root, int depth) // in bst.h distance() returns this function
{
       if (cur_root == NULL)
       {
               return 0;
       }
                double left_distance = distance(cur_root->m_left, depth + 1);
                double right_distance = distance(cur_root->m_right, depth + 1);
                return depth + left_distance + right_distance;

}
double BST::distance()
{
        double sum = distance(m_root,depth);
        if (sum == 0)
        {
                return 0;
        }
        //total distance divded by number of elemeents
        int elements = size();
        double total = sum / elements;
        total = total; //- 1;
        return total;
}

int BST::balanced(TreeNode *cur_root) // in bst.h balanced() returns this function
{

       if (cur_root == NULL)
       {
        return 0;
       } 
   // Second section
           int left_h = balanced(cur_root->m_left);

           int right_h = balanced(cur_root->m_right);   
       if ( left_h - right_h > 1)
       {
               return -1;
       }
       if (right_h - left_h > 1)
       {
               return -1;
       }
       if ( left_h == -1 || right_h == -1) 
       {
               return -1;
       }
       // third section
       else 
       {
               if (left_h > right_h)
               {
                       return left_h + 1;
               }
               else {
                       return right_h + 1;
               }
       }
}
void BST::rebalanced()
{
        if (m_root != NULL)
        {
        vector<string> elements;
        print(elements,m_root,count2);
        DeletePostOrder(m_root);
        m_root = NULL;
        insert_from_vector(*&elements, start_index, elements.size() - 1);
        }
}
void BST::insert_from_vector(vector <string> &elements, int start_index, int end_index) // in bst.h rebalanced() returns this function
{
        //the base cases where the range is of size zero or one:
        if (end_index - start_index == 0)
        {
                insert(elements[end_index]); 
                return;
        }
        if ( end_index - start_index == 1)
        {
              insert(elements[start_index]);
              insert(elements[end_index]);
              return;
        }
        int middle_index = (end_index + start_index) / 2; // middle index
        insert(elements[middle_index]);
        insert_from_vector(elements, start_index, middle_index - 1);
        insert_from_vector(elements, middle_index + 1, end_index);
}
