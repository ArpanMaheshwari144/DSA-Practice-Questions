/*Find Pair Given Difference -> Given an unsorted array Arr[] and a number N. You need to write a program to find if there exists a pair of elements in the array whose difference is N.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k;
    cin >> n >> k;
    long long int a[n], i, l, r;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    bool ans = false;

    l = 0;
    r = 1;

    while (l < n && r < n)
    {
        if (a[r] - a[l] == k && l != r)
        {
            ans = true;
            break;
        }
        else if (a[r] - a[l] < k)
        {
            r++;
        }
        else
        {
            l++;
        }
    }

    if (ans)
    // if (ans == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No";
    }

    return 0;
}