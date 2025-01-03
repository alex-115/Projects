// filename: main.cpp
// Short summary of the file contents: this file will read and execute commands for a binary search tree from standard input. The insert function inserts a string 
// into the tree. The echo function is used for commenting. The size function returns the size of the tree. The find function finds a string you type from the tree.
// The print function prints the tree nodes in alphabetical order. The distance function prints out the average distance of nodes from the root. 
// The breadth function prints out the nodes in breadth-first traversal order. The balance function checks if the tree is balanced. 
// The rebalance function balances the tree.
#include "bst.h"
#include <limits>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
        vector<string> myvec;
        int i, x;
        double distance;
        BST my_bst;
        string command;
        string arg;
        while (cin >> command)
       {
               if (command == "insert")
               {
                       cin.ignore();
                       getline(cin,arg);
                       if ( my_bst.insert(arg) == false)
                       {
                              cerr << "insert <" << arg << "> failed. String already in tree." << endl;
                       }
               }
               else if (command == "echo")
               {
                       cin.ignore();
                       getline(cin,arg);
                       cout << arg << endl;

               }
                else if (command == "size")
               {
                       cout << my_bst.size() << endl;
               }
                else if (command == "find")
               {
                       cin.ignore();
                       getline(cin,arg);
                       if (my_bst.find(arg) == false)
                       {
                              cout << "<" << arg << "> is not in tree." << endl;
                       }
                       else {
                               cout << "<" << arg << "> is in tree." << endl;
                       }
               }
                else if (command == "print")
               {
                       myvec.clear();
                       my_bst.print(myvec); 
                       x = myvec.size();
                       if (myvec.size() == 0)
                       {
                               cout << "{}" << endl;
                       }
                       else
                       {
                       cout << "{";
                       for (i = 0; i < x - 1; i++)
                       {
                               cout << myvec[i] << ", ";
                       }
                       cout << myvec[i] << "}" << endl; 
                       }
               }
                else if (command == "distance")
               {
                       distance = my_bst.distance();
                       cout << "Average distance of nodes to root = " << distance << endl;
               }
                else if (command == "breadth")
               {
                       myvec.clear();
                       my_bst.breadth(myvec);
                       x = myvec.size();
                       if (myvec.size() == 0)
                       {
                               cout << "{}" << endl;
                       }
                       else 
                       {
                       cout << "{";
                       for (i = 0; i < x - 1; i++)
                       {
                               cout << myvec[i] << ", ";
                       }
                       cout << myvec[i] << '}' << endl;
                       }
               }
                else if (command == "balanced")
               {
                       if (my_bst.balanced() == -1)
                       {
                               cout << "Tree is not balanced." << endl;
                       }
                       else {
                               cout << "Tree is balanced." << endl;
                       }

               }
                else if (command == "rebalance")
               {
                      my_bst.rebalanced();
               }

               else {
                       cin.ignore(numeric_limits<streamsize>::max(), '\n');
                       cerr << "Illegal command <" << command << ">." << endl;
               }
       }

        return 0;
}
