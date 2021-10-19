/*Allocate minimum number of pages -> You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).*/

/*Example 1:
Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output: 113
Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.*/

#include <bits/stdc++.h>
using namespace std;

bool check(int a[], int n, int m, int curr_min)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > curr_min)
        {
            return false;
        }
        if (sum + a[i] > curr_min)
        {
            cnt++;
            sum = a[i];
            if (cnt > m)
            {
                return false;
            }
        }
        else
        {
            sum += a[i];
        }
    }
    return true;
}

int findPages(int *a, int n, int m)
{
    long long sum = 0;

    if (n < m)
    {
        return -1;
    }
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    int l = 0, h = sum;
    int ans = INT_MAX;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(a, n, m, mid))
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
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
    int m;
    cin >> m;
    cout << findPages(arr, n, m);

    return 0;
}