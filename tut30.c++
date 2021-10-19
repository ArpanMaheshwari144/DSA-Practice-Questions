/*Three way partitioning -> 
Given an array of size N and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> threeWayPartition(vector<int> v, int a, int b)
{
    int start = 0, end = v.size() - 1;
    int i;

    while (i <= end)
    {
        if (v[i] < a)
        {
            swap(v[i++], v[start++]);
        }
        else if (v[i] > b)
        {
            swap(v[i], v[end--]);
        }
        else
        {
            i++;
        }
    }
    return v;
}

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        m[array[i]]++;
    }

    int a, b;
    cin >> a >> b;

    vector<int> original = array;

    int k1 = 0, k2 = 0, k3 = 0;
    int kk1 = 0, kk2 = 0, kk3 = 0;

    for (int i = 0; i < n; i++)
    {
        if (original[i] > b)
        {
            k3++;
        }
        else if (original[i] <= b && original[i] >= a)
        {
            k2++;
        }
        else if (original[i] < b)
        {
            k1++;
        }
    }

    threeWayPartition(array, a, b);

    for (int i = 0; i < k1; i++)
    {
        if (array[i] < b)
        {
            kk1++;
        }
    }
    for (int i = k1; i < k1 + k2; i++)
    {
        if (array[i] <= b && array[i] >= a)
        {
            kk2++;
        }
    }
    for (int i = k1 + k2; i < k1 + k2 + k3; i++)
    {
        if (array[i] > b)
        {
            kk3++;
        }
    }

    bool ok = 0;
    if (k1 == kk1 && k2 == kk2 && k3 == kk3)
    {
        ok = 1;
    }
    for (int i = 0; i < array.size(); i++)
    {
        m[array[i]]--;
    }
    for (int i = 0; i < array.size(); i++)
    {
        if (m[array[i]] != 0)
        {
            ok = 0;
        }
    }

    if (ok)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}