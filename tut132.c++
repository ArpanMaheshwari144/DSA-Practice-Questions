/*Maximum product subset of an array -> Given an array a, we have to find maximum product possible with the subset of elements present in the array. The maximum product can be single element also.

Examples: 
Input: a[] = { -1, -1, -2, 4, 3 }
Output: 24
Explanation : Maximum product will be ( -2 * -1 * 4 * 3 ) = 24

Input: a[] = { -1, 0 }
Output: 0
Explanation: 0(single element) is maximum product possible
 
Input: a[] = { 0, 0, 0 }
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }

    int maxNegative = INT_MIN;
    int countNegative = 0, countZero = 0;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            countZero++;
            continue;
        }

        if (a[i] < 0)
        {
            countNegative++;
            maxNegative = max(maxNegative, a[i]);
        }
        product = product * a[i];
    }

    if (countZero == n)
    {
        return 0;
    }

    if (countNegative % 2 == 1)
    {
        if (countNegative == 1 && countNegative > 0 && countZero + countNegative == n)
        {
            return 0;
        }

        product = product / maxNegative;
    }
    return product;
}

int main()
{
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum product will be: " << maxProductSubset(a, n);

    return 0;
}