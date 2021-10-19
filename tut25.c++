/*Chocolate Distribution Problem -> Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int a[n], i, j = 0, mn = INT_MAX;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    long long int m;
    cin >> m;

    for (i = m - 1; i < n; i++)
    {
        mn = min(mn, a[i] - a[j]);
        j++;
    }

    cout << mn;
    return 0;
}