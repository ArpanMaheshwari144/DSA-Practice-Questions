/*Palindromic Array -> You are given an array A of size N. Your task is to find the minimum number of operations needed to convert the given array to 'Palindromic Array'. Palindromic Array:[23,15,23] is a Palindromic Array
but [2,0,1] is not.The only allowed operation is that you can merge two adjacent elements in the array and replace them with their sum.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    i = 0;
    int j = n - 1, ans = 0;

    while (i <= j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else if (a[i] > a[j])
        {
            j--;
            a[j] += a[j + 1]; // merge operation
            ans++;
        }
        else
        {
            i++;
            a[i] += a[i + 1]; // merge operation
            ans++;
        }
    }

    cout << ans;

    return 0;
}