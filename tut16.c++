// Find if there is any subarray with equal to 0

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    long int n;
    cin >> n;

    long int a[n], i, sum = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<long int, int> m;

    for (i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0)
        {
            break;
        }
        if (m.find(sum) != m.end())
        {
            break;
        }
        m[sum]++;
    }

    if (i == n)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}