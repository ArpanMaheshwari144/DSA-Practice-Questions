/*Maximum Product Subarray -> Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.*/

#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int x, y, z, mx = a[0], mn = a[0], res = a[0];

    for (i = 1; i < n; i++)
    {
        x = a[i];
        y = mx * x;
        z = mn * x;
        mx = max(x, max(y, z));
        mn = min(x, min(y, z));
        res = max(res, max(mx, mn));
    }

    cout << res << " ";

    return 0;
}