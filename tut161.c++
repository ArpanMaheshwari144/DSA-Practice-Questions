/*Count Derangements (Permutation such that no element appears in its original position) -> A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.

Examples : 
Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one  possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9 possible derangements {1, 0, 3, 2}, {1, 2, 3, 0}, {1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
*/

#include <bits/stdc++.h>
using namespace std;

//***********Using extra space***********
int countDerangementsUsingExtraSpace(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
    }
    return dp[n];
}

//***********Without using extra space***********
int countDerangementsWithoutUsingExtraSpace(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    int a = 0;
    int b = 1;

    for (int i = 3; i <= n; i++)
    {
        int current = (i - 1) * (a + b);
        a = b;
        b = current;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int ans = countDerangementsUsingExtraSpace(n);
    cout << ans;

    // int ans = countDerangementsWithoutUsingExtraSpace(n);
    // cout << ans;

    return 0;
}