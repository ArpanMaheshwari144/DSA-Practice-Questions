// Count Palindromic Subsequences
#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s)
{
    int n = s.size();
    int dp[n][n] = {0};
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            if (s[i] == s[j])
                dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << countPalindromicSubsequence(s);

    return 0;
}