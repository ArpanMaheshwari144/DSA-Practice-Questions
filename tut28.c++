// Find the median -> Given an array arr[] of N integers, calculate the median
#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v, int n)
{

    sort(v.begin(), v.end());

    if (n % 2 == 0)
    {
        int mid = (n - 1) / 2;
        return (v[mid] + v[mid + 1]) / 2;
    }
    else
    {
        return v[(n - 1) / 2];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << find_median(a, n) << endl;
    return 0;
}