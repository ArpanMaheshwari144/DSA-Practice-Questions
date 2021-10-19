/*Smallest factorial number -> Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.*/

// Trailing 0s in n! = Count of 5s in prime factors of n! = floor(n/5) + floor(n/25) + floor(n/125) + ....

#include <bits/stdc++.h>
using namespace std;

bool check(long int p, long int n)
{
    // Keep dividing n by powers of 5 and update count
    long int i = 5, count = 0;
    while (i <= p)
    {
        count += p / i;
        i *= 5;
    }
    return count >= n;
}

int findNum(int n)
{
    if (n == 1)
    {
        return 5;
    }
    long int l = 0;
    long int h = 5 * n;
    while (l < h)
    {
        long int mid = l + (h - l) / 2;
        if (check(mid, n))
        {
            h = mid; // if mid or left of mid is answer
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    int n;
    cin >> n;
    cout << findNum(n) << "! has atleast " << n << " trailing 0";

    return 0;
}