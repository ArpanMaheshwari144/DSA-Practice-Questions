/*Find the missing number in Arithmetic Progression -> Given an array that represents elements of arithmetic progression in order. One element is missing in the progression, find the missing number.*/
#include <bits/stdc++.h>
using namespace std;

int findMissing(int a[], int n, int difference)
{
    int low = 0, high = n - 1;

    if (high <= low)
    {
        return -1;
    }
    while (low <= high)
    {
        // Binary Search
        int mid = low + (high - low) / 2;
        if (a[mid + 1] - a[mid] != difference)
        {
            return a[mid] + difference;
        }
        if (mid > 0 && a[mid] - a[mid - 1] != difference)
        {
            return a[mid - 1] + difference;
        }

        // all the elements so far in arithmetic progressionwe have to check
        if (a[mid] == a[0] + mid * difference)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return INT_MAX;
}

int main()
{
    int n;
    cin >> n;
    int arr[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int differenece = (arr[n - 1] - arr[0]) / n;

    cout << "The missing number is " << findMissing(arr, n, differenece);

    return 0;
}