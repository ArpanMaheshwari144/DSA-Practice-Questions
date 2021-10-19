/*Second most repeated string in a sequence -> Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.
Note: No two strings are the second most repeated, there will be always a single string.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s, s + n);

    string a = s[n - 1], b = s[0];
    int x = 0, mx1 = 0, mx2 = 0, c = 0;
    while (s[mx1] == s[0])
    {
        mx1++;
    }

    x = mx1;
    for (int i = x; i < n; i++)
    {
        if (s[i] == s[x])
        {
            c++;
        }
        else
        {
            if (c > mx1)
            {
                a = b;
                b = s[x];
                mx2 = mx1;
                mx1 = c;
            }
            else if (c > mx2)
            {
                mx2 = c, a = s[x];
            }
            x = i;
            c = 1;
        }
    }
    if (c > mx1)
    {
        a = b;
        b = s[x];
        mx2 = mx1;
        mx1 = c;
    }
    else if (c > mx2)
    {
        mx2 = c, a = s[x];
    }
    cout << a << '\n';
    return 0;
}
