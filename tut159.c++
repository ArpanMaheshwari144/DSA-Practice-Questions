/*Longest Palindromic Subsequence -> Given a sequence, find the length of the longest palindromic subsequence in it.

Example:
Input: GEEKSFORGEEKS
Output: 5
*/

#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string X, string Y, int n, int m)
{
    int t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    string X = "GEEKSFORGEEKS";
    string Y = string(X.rbegin(), X.rend()); // Use of reverse iterators

    int n = X.size();
    int m = Y.size();

    cout << "The length of longest palindromic subsequence is " << longestPalindromicSubsequence(X, Y, n, m);

    return 0;
}