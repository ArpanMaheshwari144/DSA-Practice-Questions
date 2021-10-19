/*Smallest subset with sum greater than all other elements -> Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.

Examples :
Input : arr[] = {3, 1, 7, 1}
Output : 1
Smallest subset is {7}. Sum of
this subset is greater than all
other elements {3, 1, 1}

Input : arr[] = {2, 1, 2}
Output : 2
In this example one element is not 
enough. We can pick elements with 
values 1, 2 or 2, 2. In any case, 
the minimum count is 2.
*/

#include <bits/stdc++.h>
using namespace std;

int minElements(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    sort(arr, arr + n);

    int currSum = 0, count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        currSum = currSum + arr[i];
        count++;
        int remainingSum = sum - currSum;
        if (currSum > remainingSum)
        {
            break;
        }
    }
    return count;
}

int main()
{
    int arr[] = {3, 1, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest Subset of size is : " << minElements(arr, n) << endl;

    return 0;
}