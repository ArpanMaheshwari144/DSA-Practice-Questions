// Minimise the maximun difference between heights
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int small = a[0] + k;
    int big = a[n - 1] - k;

    if (small > big)
    {
        swap(small, big);
    }

    for (i = 1; i < n; i++)
    {
        int sub = a[i] - k;
        int add = a[i] + k;

        if (sub >= small || add <= big)
        {
            continue;
        }
        else if (big - sub <= add - small)
        {
            small = sub;
        }
        else
        {
            big = add;
        }
    }

    cout << min(big - small, a[n - 1] - a[0]);

    return 0;
}