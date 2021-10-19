// Given an array which consists of 0, 1 and 2. Sort the array without using any sorting algo
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

    int c1 = 0, c2 = 0, c3 = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            c1++;
        }
        else if (a[i] == 1)
        {
            c2++;
        }
        else
        {
            c3++;
        }
    }

    for (i = 0; i < c1; i++)
    {
        a[i] = 0;
    }
    for (i = c1; i < c1 + c2; i++)
    {
        a[i] = 1;
    }
    while (c3--)
    {
        a[i++] = 2;
    }

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}