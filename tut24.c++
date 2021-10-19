// Trapping Rain Water

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

    long long int sum = 0, l, r, lmax = 0, rmax = 0;
    l = 0;
    r = n - 1;

    while (l < r)
    {
        if (lmax < rmax)
        {
            if (lmax < a[l])
            {
                lmax = a[l];
            }
            else
            {
                sum += lmax - a[l];
                l++;
            }
        }
        else
        {
            if (rmax < a[r])
            {
                rmax = a[r];
            }
            else
            {
                sum += rmax - a[r];
                r--;
            }
        }
    }
    cout << sum;
    return 0;
}