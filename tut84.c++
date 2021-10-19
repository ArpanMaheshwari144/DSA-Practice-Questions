/*K-th element of two sorted Arrays -> Given two sorted arrays A and B of size M and N respectively and an element k. The task is to find the element that would be at the k’th position of the final sorted array(1-based indexing).*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int m, n, k, ans = -1;
    cin >> m >> n >> k;
    long long int a[m], b[n], i, j, index = 0;
    for (i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    i = 0;
    j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            i++;
            index++;
            if (index == k)
            {
                ans = a[i - 1];
                break;
            }
        }
        else
        {
            j++;
            index++;
            if (index == k)
            {
                ans = b[j - 1];
                break;
            }
        }
    }
    cout << ans;
    return 0;
}