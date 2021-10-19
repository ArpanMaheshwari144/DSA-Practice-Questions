/*Sorted matrix -> Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i, j;
    int a[n * n], k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[k++];
        }
    }

    sort(a, a + n * n);

    for (i = 0; i < n * n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}