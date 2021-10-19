/*Edit Distance -> Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:
1. Insert
2. Remove
3. Replace*/

#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t)
{
    int dp[101][101]; // dp array
    int i, j, n = s.length(), m = t.length();
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t);
    return 0;
}