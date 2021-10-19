/*Consecutive elements -> For a given string delete the elements which are appearing more than once consecutively. All letters are of lowercase.*/

#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(string s)
{
    if (s.length() < 2)
    {
        cout << s << endl;
    }
    else
    {
        int i, j = 0;
        for (i = 1; i < s.length(); i++)
        {
            if (s[j] != s[i])
            {
                j++;
                s[j] = s[i];
            }
        }
        cout << s.substr(0, j + 1) << endl;
    }
}

int main()
{
    string s;
    cin >> s;

    removeDuplicates(s);

    return 0;
}