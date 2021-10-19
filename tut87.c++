/*Find pivot element in a sorted and rotated array*/
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(int a[], int n)
{
    if (n == 0)
    {
        return -1;
    }

    // array is not rotated but sorted
    if (n == 1 || a[0] < a[n - 1])
    {
        return 0;
    }

    // Binary Search
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] > a[mid + 1])
        {
            return mid + 1;
        }
        else if (a[low] <= a[mid])
        {
            low = mid + 1; // checking on the right-hand side of the array
        }
        else
        {
            high = mid - 1; // checking on the left-hand side of the array
        }
    }
    return 0;
}

int main()
{
    int arr[] = {10, 11, 12, 13, 14};

    cout << pivotIndex(arr, 5); // return minimum pivot index of that element in the array

    return 0;
}