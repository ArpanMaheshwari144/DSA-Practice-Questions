/*K-th Largest Sum Contiguous Subarray -> Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.

Examples: 
Input: a[] = {20, -5, -1}, k = 3
Output: 14
Explanation: 
Subarrays are: 
(20) => 20
(20, -5) => 20 + (-5) => 15 
(20, -5, -1) => 20 + (-5) + (-1) => 14 
(-5) => -5
(-5, -1) => -5 + (-1) => -6
(-1) => -1
All sum of contiguous subarrays are (20, 15, 14, -5, -6, -1) so the 3rd largest sum is 14.

Input: a[] = {10, -10, 20, -40}, k = 6
Output: -10 
Explanation: The 6th largest sum among sum of all contiguous subarrays is -10.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, -10, 20, -40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    vector<int> ans;
    long int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = i; j < n; j++)
        {
            temp += arr[j];
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>()); // sort in descending order
    cout << ans[k - 1] << " ";

    return 0;
}