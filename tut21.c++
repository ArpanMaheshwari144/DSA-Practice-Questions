/*Maximum profit by buying and selling a share at most twice -> In a daily share trading, a buyer buys shares in the morning and sells it on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.*/

/*Example ->
Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12 and 75
Buy at price 10, sell at 22, buy at 5 and sell at 80
22 - 10 + 80 - 5 = 12 + 75 = 87*/

#include <iostream>
using namespace std;

int maxProfit(int a[], int n, int k)
{
    if (k >= n / 2)
    {
        int maxp = 0, i;
        for (i = 0; i < n; i++)
        {
            if (a[i] > a[i - 1])
            {
                maxp += a[i] - a[i - 1];
            }
        }
        return maxp;
    }

    int mx[k + 1] = {0};
    int lp[k + 1];

    for (int i = 0; i <= k; i++)
    {
        lp[i] = 32000;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            mx[j] = max(mx[j], a[i] - lp[j]);
            lp[j] = min(lp[j], a[i] - mx[j - 1]);
        }
    }

    return mx[k];
}

int main()
{
    int n;
    cin >> n;
    int a[n], i;
    int k = 2;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << maxProfit(a, n, k);
    return 0;
}