/*Parenthesis Checker -> Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    long int i;

    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == '}')
            {
                if (st.size() == 0 || st.top() != '{')
                {
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == ']')
            {
                if ((int)st.size() == 0 || st.top() != '[')
                {
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                if (st.size() == 0 || st.top() != '(')
                {
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    if (i == s.length() && (int)st.size() == 0)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced";
    }

    return 0;
}