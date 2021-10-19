/*Find Missing And Repeating -> Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int s1, s2;
    s1 = (n * (n + 1)) / 2;
    s2 = (n * (n + 1) * (2 * n + 1)) / 6;

    for (i = 0; i < n; i++)
    {
        s1 -= a[i];
        s2 -= (a[i] * a[i]);
    }

    s2 = s2 / s1;

    int missing = (s1 + s2) / 2;
    int repeat = missing - s1;

    cout << "Missing number is " << missing << endl;
    cout << "Repeating number is " << repeat;
    return 0;
}