/*First and last occurrences of X -> Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array just print '-1'.*/

#include <bits/stdc++.h>
using namespace std;

int first(int a[], int l, int h, int x, int n)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ((mid == 0 || x > a[mid - 1]) && a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int last(int a[], int l, int h, int x, int n)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ((mid == n - 1 || x < a[mid + 1]) && a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (first(a, 0, n - 1, x, n) == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << first(a, 0, n - 1, x, n) << " " << last(a, 0, n - 1, x, n);
    }

    return 0;
}