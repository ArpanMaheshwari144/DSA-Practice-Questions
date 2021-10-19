/*Transform One String to Another using Minimum Number of Given Operation -> Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation. */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int i, j, map[256] = {0};

    for (i = 0; i < s2.length(); i++)
    {
        map[s2[i]]++;
    }
    for (i = 0; i < s1.length(); i++)
    {
        map[s1[i]]--;
    }
    for (i = 0; i < 256; i++) // there are 256 characters in the ascii table
    {
        if (map[i] != 0)
        {
            break;
        }
    }
    if (i != 256)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int ans = 0;
        i = s1.length() - 1;
        j = s2.length() - 1;

        while (i >= 0 && j >= 0)
        {
            if (s1[i] == s2[j])
            {
                i--;
                j--;
            }
            else
            {
                while (i >= 0 && s1[i] != s2[j])
                {
                    i--;
                    ans++;
                }
            }
        }
        cout << ans;
    }

    return 0;
}