/*Maximum subsequence sum such that no three are consecutive -> Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.

Examples : 
Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is 2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013

Input: arr[] = {100, 1000, 100, 1000, 1}
Output: 2101
100 + 1000 + 1000 + 1 = 2101

Input: arr[] = {1, 1, 1, 1, 1}
Output: 4

Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 27
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dp[n] = {0};
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max({arr[0] + arr[1], arr[1] + arr[2], arr[0] + arr[2]});

    for (int i = 3; i < n; i++)
    {
        dp[i] = max({dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]});
    }

    cout << dp[n - 1];

    return 0;
}