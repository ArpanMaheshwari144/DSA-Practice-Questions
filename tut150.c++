/*Sum of minimum and maximum elements of all subarrays of size k. -> Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
Examples: 
Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     Sum of all min & max = 6 + 4 + 4 + 4 = 18    
*/

#include <bits/stdc++.h>
using namespace std;

void sumOfKSubArray(int arr[], int n, int K)
{
    deque<int> dqMax, dqMin;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // Remove all elements which are out of this window
        if (!dqMax.empty() && dqMax.front() == i - K)
        {
            dqMax.pop_front();
        }

        // Remove all elements which are out of this window
        if (!dqMin.empty() && dqMin.front() == i - K)
        {
            dqMin.pop_front();
        }

        // remove all previous greater element that are useless
        while (!dqMax.empty() && arr[i] > arr[dqMax.back()])
        {
            dqMax.pop_back();
        }

        // remove all previous smaller element that are useless
        while (!dqMin.empty() && arr[i] < arr[dqMin.back()])
        {
            dqMin.pop_back();
        }

        dqMax.push_back(i);
        dqMin.push_back(i);

        if (i >= K - 1)
        {
            cout << "Min = " << arr[dqMin.front()] << " "
                 << "Max = " << arr[dqMax.front()] << " ==> "
                 << "Min + Max = " << arr[dqMax.front()] + arr[dqMin.front()] << endl;
            sum += arr[dqMax.front()] + arr[dqMin.front()];
        }
    }

    cout << "Total Sum = " << sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
    sumOfKSubArray(arr, n, K);

    return 0;
}