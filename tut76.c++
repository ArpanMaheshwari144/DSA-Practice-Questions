/*Majority Element -> Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.*/
#include <bits/stdc++.h>
using namespace std;

bool isMajority(int a[], int n, int candidate)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == candidate)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int majorityElement(int a[], int n)
{
    int ans = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ans = a[i];
        }
        if (ans == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    if (isMajority(a, n, ans))
    {
        return ans;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << majorityElement(a, n);
    return 0;
}