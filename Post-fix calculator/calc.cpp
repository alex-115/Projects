//filename: Calc.cpp
//Name: Alejandro Barajas
//INGinious username: ajbarajas1
//Summary: this file executes the required operations to pass a postfix calculator, it begins reading the input of the user then runs it through different cases in order to operate as a post fix calculator using stacks.
#include <iostream>
#include <cctype>
#include <cmath>
#include "dstack.h"
using namespace std;
int main()
{
        double value;
        char mchar;
        double a, b, c = 0;
        Dstack stack;

        while (cin.peek() != EOF)
        {
                if (isspace(cin.peek()))
                {
                        cin.ignore();
                }
                else if (isdigit(cin.peek()))
                {
                        cin >> value;
                        if(cin.peek() == '.')
                        {
                                cerr << "Error: Invalid expression." << endl;
                                exit(1);
                        }
                        stack.push(value);
                }
                else if (cin.peek() == '.')
                {
                        cin >> value;
                        if (!isdigit(cin.peek()))
                        {
                                if (cin.peek() == '.')
                                {
                                cerr << "Error: Invalid expression." << endl;
                                exit(1);
                                }
                        }
                        stack.push(value);
                        
                

                }
                else if (!isdigit(cin.peek()))
                {
                        cin >> mchar;
                         if (mchar == '+' && stack.size() >= 2)
                        {
                        stack.pop(a);
                        stack.pop(b);
                        c = a + b;
                        stack.push(c);
                        }
                        else if (mchar == '-' && stack.size() >=2)
                        {
                                stack.pop(a);
                                stack.pop(b);
                                c = b - a;
                                stack.push(c);
                        }
                        else if (mchar == '/' && stack.size() >= 2)
                        {
                                stack.pop(a);
                                stack.pop(b);
                                c = b / a;
                                stack.push(c);
                        }
                        else if (mchar == '*' && stack.size() >= 2)
                        {
                                stack.pop(a);
                                stack.pop(b);
                                c = a * b;
                                stack.push(c);
                        }
                         else if (mchar == '^' && stack.size() >= 2)
                        {
                                stack.pop(a);
                                stack.pop(b);
                                c = pow(b,a);
                                stack.push(c);
                        }
                        else{
                                cerr << "Error: Invalid expression." << endl;
                               exit(1);
                        }
                } else {
                       cerr << "Error: Invalid expression." << endl;
                       exit(1);
               }
        }
        if (stack.size() == 1)
        {
        stack.pop(c);
        cout << c << endl;
        } else { cerr << "Error: Invalid expression." << endl;
                exit(1);
        }
        return 0;
}

