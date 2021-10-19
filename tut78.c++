/*Zero Sum Subarrays -> You are given an array A[] of size N. Find the total count of sub-arrays having their sum equal to 0.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0, count = 0;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == 0)
            {
                count++;
            }
        }
    }
    cout << count;
    cout << endl;
    return 0;
}