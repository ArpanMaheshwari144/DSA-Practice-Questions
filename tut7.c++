// Write a program to cyclically rotate an array by one
#include <iostream>
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

    int last = a[n - 1];

    for (i = n - 1; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }

    a[0] = last;

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}