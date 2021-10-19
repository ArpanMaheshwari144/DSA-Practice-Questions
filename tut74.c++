/*Finding Square Root using Binary Search*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int l = 1, h = n, ans = 0;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            l = mid + 1;
            ans = mid; // this condition is for those numbers which are not perfect squares
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << ans;
    return 0;
}