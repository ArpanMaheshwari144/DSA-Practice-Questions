/*Sliding Window Maximum (Maximum of all subarrays of size k) -> Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.

Examples : 
Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfAllSubarraysOfSizeK(int arr[], int n, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    list<int> l;

    if (k > n)
    {
        ans.push_back(*max_element(arr, arr + n));
        return ans;
    }

    while (j < n)
    {
        while (l.size() > 0 && l.back() < arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());

            if (l.front() == arr[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> v = maxOfAllSubarraysOfSizeK(arr, n, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}