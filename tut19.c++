/* Longest consecutive subsequence -> Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.*/

#include <iostream>
using namespace std;

int main()
{
    long long int n, m = 0, count = 0, m1 = 0;
    cin >> n;
    long long int a, i;
    long long int h[100005] = {0};
    for (i = 0; i < n; i++)
    {
        cin >> a;
        h[a] = 1;
        m1 = max(a, m1);
    }
    for (i = 0; i <= m1; i++)
    {
        if (h[i] == 1)
        {
            count++;
        }
        else
        {
            m = max(m, count);
            count = 0;
        }
    }
    m = max(m, count);
    cout << m << endl;
    return 0;
}