// filename: BST.h
// Short summary of the file contents: This file contains the functions of a binary search tree. There are also comments that indicate the private helper functions. 
#ifndef BST_H
#define BST_H
#include <iostream>
#include <vector>
using namespace std;
class BST
{
        public:
                BST();
                ~BST() { DeletePostOrder( m_root);} 
                bool insert(string str) { return insert(str, m_root);}
                int size();
                bool find(string str) { return find(str, m_root);} 
                void print(vector<string> &myvec) { print(myvec, m_root, count2);}  
                void breadth(vector<string> &myvec);
                double distance();
                int balanced() { return balanced(m_root);}
                void rebalanced();
        private:
                class TreeNode{
                        public:
                                TreeNode(string value)
                                {
                                        m_value = value;
                                        m_left = NULL;
                                        m_right = NULL;
                                }
                                string m_value;
                                TreeNode *m_left;
                                TreeNode *m_right;
                };
                void DeletePostOrder(TreeNode *cur_root);
                void insert_from_vector(vector <string> &elements, int start_index, int end_index);
                int balanced(TreeNode *cur_root);
                double distance(TreeNode *&cur_root, int depth);// private helper func
                bool find(string s1, TreeNode *&cur_root); // private helper function
                bool insert(string s1, TreeNode *&cur_root); // private helper func
                void print(vector<string> &myvec, TreeNode *&cur_root, int count2);
                vector <string> elements;
                string s1;
                int depth = 0;
                double avg = 0;
                int start_index = 0;
                int end_index;
                int count = 0;
                int count2 = 0;
                TreeNode *m_root;
};
#endif
