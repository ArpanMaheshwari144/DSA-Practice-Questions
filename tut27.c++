/*Minimum swaps and K together -> Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.*/

#include <bits/stdc++.h>
using namespace std;

int answer(int arr[], int n, int k)
{
    // less than equals to k
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }

    // find unwanted elements in current window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
        {
            bad++;
        }
    }

    // initialize answer with 'bad' value of current window
    int ans = bad;
    for (int i = 0, j = count; j < n; i++, j++)
    {
        // decrement count of prevoius window
        if (arr[i] > k)
        {
            bad--;
        }

        // increment count of current window
        if (arr[j] > k)
        {
            bad++;
        }

        // update ans if count of 'bad' is less than in current window
        ans = min(ans, bad);
    }
    return ans;
}

int main()
{

    int size;
    cin >> size;
    int i, arr[size], k;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << answer(arr, size, k);

    return 0;
}
