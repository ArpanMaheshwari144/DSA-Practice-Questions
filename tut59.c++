/*Longest Common Subsequence -> Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.*/
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(int x, int y, string s1, string s2)
{
    int t[x + 1][y + 1];
    int i, j;
    for (i = 0; i <= x; i++)
    {
        for (j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[x][y];
}

int main()
{
    int x, y;
    cin >> x >> y;
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubsequence(x, y, s1, s2);
    return 0;
}