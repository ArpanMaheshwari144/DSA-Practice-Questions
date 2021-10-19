/* Tug of War -> Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the absolute difference of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets must be strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.

For example: 
let given set be {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, the size of set is 10. 
Output for this set should be {4, 100, 1, 23, 20} and {3, 5, -3, 89, 54}. Both output subsets are of size 5 and sum of elements in both subsets is same (148 and 148). 

Let us consider another example where n is odd. 
Let given set be {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}. 
The output subsets should be {45, -34, 12, 98, -1} and {23, 0, -99, 4, 189, 4}. The sums of elements in two subsets are 120 and 121 respectively.

The following solution tries every possible subset of half size. If one subset of half size is formed, the remaining elements form the other subset. We initialize current set as empty and one by one build it. There are two possibilities for every element, either it is part of current set, or it is part of the remaining elements (other subset). We consider both possibilities for every element. When the size of current set becomes n/2, we check whether this solutions is better than the best solution available so far. If it is, then we update the best solution.
*/

#include <bits/stdc++.h>
using namespace std;

void tugOfWar(int arr[], int n, int i, int sum1, int sum2, vector<int> arr1, vector<int> arr2, bool res[], int &diff)
{
    if (i == n)
    {
        if (arr1.size() == (n + 1) / 2)
        {
            if (abs(sum1 - sum2) < diff)
            {
                diff = abs(sum1 - sum2);
                for (int i = 0; i < n; i++)
                {
                    res[i] = false;
                }
                for (int i = 0; i < arr1.size(); i++)
                {
                    res[arr1[i]] = true;
                }
            }
        }
        return;
    }

    arr1.push_back(i); // include in first set
    tugOfWar(arr, n, i + 1, sum1 + arr[i], sum2, arr1, arr2, res, diff);
    arr1.pop_back(); // backtrack

    arr2.push_back(i); // include in second set
    tugOfWar(arr, n, i + 1, sum1, sum2 + arr[i], arr1, arr2, res, diff);
    arr2.pop_back(); // backtrack
}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> arr1, arr2;
    bool res[n];
    int diff = INT_MAX;
    tugOfWar(arr, n, 0, 0, 0, arr1, arr2, res, diff);

    cout << "Set1: ";
    for (int i = 0; i < n; i++)
    {
        if (res[i] == true)
        {
            cout << arr[i] << " ";
        }
    }

    cout << "\nSet2: ";
    for (int i = 0; i < n; i++)
    {
        if (res[i] == false)
        {
            cout << arr[i] << " ";
        }
    }

    cout << "\nMinimum Difference: " << diff;

    return 0;
}