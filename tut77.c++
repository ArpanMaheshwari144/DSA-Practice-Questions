/*Stickler Thief -> Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int a[n], i;
    long long int dp[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << a[0] << endl;
    }
    else if (n == 2)
    {
        cout << max(a[0], a[1]) << endl;
    }
    else
    {
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for (i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
        }
        cout << dp[n - 1];
    }
    return 0;
}