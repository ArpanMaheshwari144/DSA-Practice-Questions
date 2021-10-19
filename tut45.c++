/*Longest Repeating Subsequence -> Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.*/
#include <bits/stdc++.h>
using namespace std;

int lrs(string s, int n)
{
    int dp[n + 1][n + 1];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == s[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    cout << lrs(s1, n);

    return 0;
}