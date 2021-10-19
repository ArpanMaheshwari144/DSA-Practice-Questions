/*Array Subset of another array -> Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isSubset(long long int arr1[], long long int n, long long int arr2[], long long int m)
{
    if (m > n)
    {
        return false;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    long long int i = 0;
    long long int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] == arr2[j])
        {
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            return false;
        }
    }

    if (j == m)
    {
        return true;
    }
    return false;
}

int main()
{
    long long int n, m;
    cin >> n >> m;
    long long int a1[n], a2[m], i;
    for (i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> a2[i];
    }

    if (isSubset(a1, n, a2, m))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    // OR

    /*long long int m, n;
    cin >> m >> n;

    long long int a[m], b[n], i;
    unordered_map<long long int, long long int> m1, m2;

    for (i = 0; i < m; i++)
    {
        cin >> a[i];
        m1[a[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        m2[b[i]]++;
    }

    for (i = 0; i < n; i++)
    {
        if (m1[b[i]] < m2[b[i]])
        {
            break;
        }
    }

    if (i == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }*/

    return 0;
}