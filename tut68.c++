/*Wildcard string matching -> Given two strings where first string may contain wild card characters and second string is a normal string. Write a function that returns true if the two strings match. The following are allowed wild card characters in first string.
* --> Matches with 0 or more instances of any character or set of characters.
? --> Matches with any one character.*/

#include <bits/stdc++.h>
using namespace std;

bool match(string s, string p, int i, int j, int n, int m)
{
    if (i == n && j == m)
    {
        return true;
    }
    if (s[i] == '*' && i < n - 1 && j == m)
    {
        return false;
    }
    if (s[i] == '?' || s[i] == p[j])
    {
        return match(s, p, i + 1, j + 1, n, m);
    }
    else if (s[i] == '*')
    {
        return match(s, p, i + 1, j, n, m) || match(s, p, i, j + 1, n, m);
    }
    return false;
}

int main()
{
    string s, p;
    cin >> s >> p;
    if (match(s, p, 0, 0, s.size(), p.size()))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}