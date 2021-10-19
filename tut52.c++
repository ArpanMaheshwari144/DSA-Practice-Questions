/*Word Break -> Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 
Example 1:
Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    string dict[n];
    string s;

    unordered_set<string> st;
    for (i = 0; i < n; i++)
    {
        cin >> dict[i];
        st.insert(dict[i]);
    }
    cin >> s;

    n = s.length();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp)); // to set the values in dp array

    dp[n] = 1;
    for (i = n - 1; i >= 0; i--)
    {
        string word;
        for (j = i; j < n; j++)
        {
            word.push_back(s[j]);
            if (st.find(word) != st.end())
            {
                if (dp[j + 1])
                {
                    dp[i] = 1;
                }
            }
        }
    }
    cout << dp[0] << endl;

    return 0;
}