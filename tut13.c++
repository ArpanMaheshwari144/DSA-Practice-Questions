// Find all pairs on integer array whose sum is equal to given number

#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsCount(int a[], int n, int k)
{
    int count = 0, i;
    unordered_map<int, int> m;

    for (i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        count += m[k - a[i]];

        if (k - a[i] == a[i])
        {
            count--;
        }
    }

    return count / 2;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = getPairsCount(a, n, k);
    cout << ans << " ";

    return 0;
}