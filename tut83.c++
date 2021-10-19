/*Searching in an array where adjacent differ by at most k -> A step array is an array of integer where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple element exist return the first occurrence of the key.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k, x; // k is difference of array elements, x is element to be found in which index
    cin >> k >> x;
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    i = 0;
    while (i < n)
    {
        if (a[i] == x)
        {
            break;
        }
        else
        {
            i = i + max(1, abs(a[i] - x) / k);
        }
    }

    cout << "Element found index at " << i;

    return 0;
}