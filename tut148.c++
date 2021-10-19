/*Reverse a stack using recursion -> Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)
*/

#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int value)
{
    if (s.size() == 0)
    {
        s.push(value);
        return;
    }

    int b = s.top();
    s.pop();
    insert(s, value);
    s.push(b);
}

void reverseStack(stack<int> &s)
{
    if (s.size() == 0)
    {
        return;
    }

    int a = s.top();
    s.pop();
    reverseStack(s);
    insert(s, a);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);
    cout << "After reversing the elements in the stack are: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}