/*Minimum removals from array to make max – min <= K -> Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements. 

Examples: 
Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20}, k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}, k = 2
Output : 3
Explanation: There are multiple ways to remove elements in this case. One among them is to remove 5, 6, 8. The other is to remove 1, 2, 5
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// Using Dynamic Programming
int removal(int arr[], int n, int k, int i, int j)
{
    // Base case
    if (i >= j)
    {
        return 0;
    }

    if (arr[j] - arr[i] <= k)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // 1 is for removed element
    return dp[i][j] = 1 + min(removal(arr, n, k, i + 1, j), removal(arr, n, k, i, j - 1));
}

// Using Binary Search
int findindex(int arr[], int n, int i, int k)
{
    // Starting index to search will be i+1 and ending index will be n-1
    int start = i + 1, end = n - 1, index = -1;

    // Binary search for maximum valid index
    while (start < end)
    {
        int mid = start + (end - start) / 2;

        // Search on right side to increase index value
        if (arr[mid] - arr[i] <= k)
        {
            index = mid;
            start = mid + 1;
        }

        else
        {
            end = mid;
        }
    }
    return index;
}

int main()
{
    // ******************Using Dynamic Programming******************
    // int arr[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int k = 4;
    // sort(arr, arr + n);
    // memset(dp, -1, sizeof(dp));

    // cout << removal(arr, n, k, 0, n - 1);

    // ******************Using Binary Search******************
    int arr[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    sort(arr, arr + n);

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        /* for each index i find maximum index j such that a[j] - a[i] <= k && removals are less number of removals is 
        n-(j - i + 1) */
        int j = findindex(arr, n, i, k);

        //if valid index is found
        if (j != -1)
        {
            ans = min(ans, n - (j - i + 1));
        }
    }

    cout << ans;

    return 0;
}