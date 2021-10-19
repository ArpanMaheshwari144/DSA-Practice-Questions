/*Smallest subarray with sum greater than x -> Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.*/

#include <bits/stdc++.h> // it include all library
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int a[n], i, l = 0, sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mn = INT_MAX;

    for (i = 0; i < n; i++)
    {
        sum += a[i];

        while (sum > x)
        {
            mn = min(mn, i - l + 1);
            sum -= a[l];
            l++;
        }
    }
    cout << mn;
    return 0;
}