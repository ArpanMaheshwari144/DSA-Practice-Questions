/*Expression contains redundant bracket or not -> Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if same sub-expression is surrounded by unnecessary or multiple brackets. Print ‘Yes’ if redundant else ‘No’.
Note: Expression may contain ‘+‘, ‘*‘, ‘–‘ and ‘/‘ operators. Given expression is valid and there are no white spaces present.

Example: 
Input: 
1. ((a+b))
2. (a+(b)/c)
3. (a+b*(c-d))
Output: 
1. Yes
2. Yes
3. No
Explanation:
1. ((a+b)) can reduced to (a+b), this Redundant
2. (a+(b)/c) can reduced to (a+b/c) because b is
surrounded by () which is redundant.
3. (a+b*(c-d)) doesn't have any redundant or multiple
brackets.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string &str)
{
    // stack<char> s;
    // int i = 0;
    // while (i != str.size())
    // {
    //     if (str[i] == ')')
    //     {
    //         if (s.top() == '(')
    //         {
    //             return true;
    //         }
    //         int x = 0;
    //         while (s.top() != '(')
    //         {
    //             s.pop();
    //             x++;
    //         }
    //         s.pop();
    //         if (x == 1)
    //         {
    //             return true;
    //         }
    //     }
    //     else
    //     {
    //         s.push(str[i]);
    //     }
    //     i++;
    // }
    // return false;

    //************************************OR****************************************

    // count of no of signs
    int a = 0, b = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' && str[i + 2] == ')')
        {
            return true;
        }
        if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
        {
            a++;
        }
        if (str[i] == '(')
        {
            b++;
        }
    }
    if (b > a)
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "((a+b))";
    // string s = "(a+(b)/c)";
    // string s = "(a+b*(c-d))";

    bool ans = checkRedundancy(s);
    if (ans)
    {
        cout << "Yes, Redundant Brackets found";
    }
    else
    {
        cout << "No, Redundant Brackets found";
    }

    return 0;
}