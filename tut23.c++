/*Find the triplets that sum to a given value -> Given an array A[] of N numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int n, sum;
    cin >> n >> sum;

    long long int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    long long int j, k, flag = 0;
    for (i = 0; i < n; i++)
    {
        j = i + 1;
        k = n - 1;

        while (j < k)
        {
            if (a[i] + a[j] + a[k] == sum)
            {
                flag = 1;
                break;
            }
            else if (a[i] + a[j] + a[k] < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (flag)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}