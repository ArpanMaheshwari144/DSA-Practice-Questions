/*Maximum sum of absolute difference of any permutation -> Given an array, we need to find the maximum sum of absolute difference of any permutation of the given array.

Examples:
Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are 
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is 
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumDifference(int arr[], int n)
{
    // final sequence stored in the vector
    vector<int> v;

    // sort the original array so that we can retrieve the large elements from the end of array elements
    sort(arr, arr + n);

    /*In this loop first we will insert one smallest element not entered till that time in final sequence
    and then enter a highest element (not entered till that time) in final sequence so that we
    have large difference value. This process is repeated till all array has completely entered in sequence.
    Here, we have loop till n/2 because we are inserting two elements at a time in loop.*/
    for (int i = 0; i < n / 2; i++)
    {
        v.push_back(arr[i]);
        v.push_back(arr[n - i - 1]);
    }

    // If there are odd elements, push the middle element at the end.
    if (n % 2 != 0)
    {
        v.push_back(n / 2);
    }

    // variable to store the maximum sum of absolute difference
    int maxSum = 0;

    // In this loop absolute difference of elements for the final sequence is calculated.
    for (int i = 0; i < n - 1; ++i)
    {
        maxSum = maxSum + abs(v[i] - v[i + 1]);
    }

    // absolute difference of last element and 1st element
    maxSum = maxSum + abs(v[n - 1] - v[0]);

    // return the value
    return maxSum;
}

int main()
{
    int arr[] = {1, 2, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum sum is: " << maxSumDifference(arr, n);

    return 0;
}