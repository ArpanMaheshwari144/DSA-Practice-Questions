/*The painter’s partition problem -> We have to paint n boards of length {A1, A2, .. An}. There are k painters available and each takes 1 unit time to paint 1 unit of board. The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Examples :
Input : k = 2, A = {10, 10, 10, 10} 
Output : 20.
Here we can divide the boards into 2
equal sized partitions, so each painter 
gets 20 units of board and the total
time taken is 20. 
Input : k = 2, A = {10, 20, 30, 40} 
Output : 60.
Here we can divide first 3 boards for
one painter and the last board for 
second painter.
From the above examples, it is obvious that the strategy of dividing the boards into k equal partitions won’t work for all the cases. We can observe that the problem can be broken down into: Given an array A of non-negative integers and a positive integer k, we have to divide A into k of fewer partitions such that the maximum sum of the elements in a partition, overall partitions is minimized. So for the second example above, possible divisions are:
* One partition: so time is 100.
* Two partitions: (10) & (20, 30, 40), so time is 90. Similarly (10, 20) & (30, 40), so time is 70
or (10, 20, 30) & (40), so time is 60; so this means the minimum time: (100, 90, 70, 60) is 60.*/

#include <bits/stdc++.h>
using namespace std;

// return the maximum element from the array
int getMax(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// return the sum of the elements in the array
int getSum(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}

int numberOfPainters(int a[], int n, int mid)
{
    int painter = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > mid)
        {
            sum = a[i];
            painter++;
        }
    }
    return painter;
}

int partition(int a[], int n, int k)
{
    int low = getMax(a, n);
    int high = getSum(a, n);

    while (low < high)
    {
        int mid = low + (high - low) / 2; // mid is the time
        int requiredPainters = numberOfPainters(a, n, mid);

        if (requiredPainters <= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1; // serach on right side
        }
    }
    return low;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << partition(a, n, k);

    return 0;
}

// OR

// function to calculate sum between two indices in array
// int sum(int arr[], int from, int to)
// {
//     int total = 0;
//     for (int i = from; i <= to; i++)
//     {
//         total += arr[i];
//     }
//     return total;
// }

// // for n boards and k partitions
// int partition(int arr[], int n, int k)
// {
//     // base cases
//     if (k == 1) // one partition
//         return sum(arr, 0, n - 1);
//     if (n == 1) // one board
//         return arr[0];

//     int best = INT_MAX;

//     // find minimum of all possible maximum k-1 partitions to the left of arr[i], with i elements, put k-1 th divider
//     // between arr[i-1] & arr[i] to get k-th partition
//     for (int i = 1; i <= n; i++)
//     {
//         best = min(best, max(partition(arr, i, k - 1), sum(arr, i, n - 1)));
//     }

//     return best;
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     int a[n], i;
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     cout << partition(a, n, k) << endl;

//     return 0;
// }

// OR

// function to calculate sum between two indices in array
// int sum(int arr[], int from, int to)
// {
//     int total = 0;
//     for (int i = from; i <= to; i++)
//     {
//         total += arr[i];
//     }
//     return total;
// }

// // bottom up tabular dp
// int findMax(int arr[], int n, int k)
// {
//     // initialize table
//     int dp[k + 1][n + 1] = {0};

//     // base cases k=1
//     for (int i = 1; i <= n; i++)
//     {
//         dp[1][i] = sum(arr, 0, i - 1);
//     }

//     // n=1
//     for (int i = 1; i <= k; i++)
//     {
//         dp[i][1] = arr[0];
//     }

//     // 2 to k partitions
//     for (int i = 2; i <= k; i++)
//     { // 2 to n boards
//         for (int j = 2; j <= n; j++)
//         {
//             // track minimum
//             int best = INT_MAX;

//             // i-1 th separator before position arr[p=1..j]
//             for (int p = 1; p <= j; p++)
//             {
//                 best = min(best, max(dp[i - 1][p], sum(arr, p, j - 1)));
//             }

//             dp[i][j] = best;
//         }
//     }

//     // required
//     return dp[k][n];
// }

// // driver function
// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     int a[n], i;
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     cout << findMax(a, n, k) << endl;
//     return 0;
// }