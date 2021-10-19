/*Sort by Set Bit Count -> Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 
Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.*/
#include <bits/stdc++.h>
using namespace std;

int sortBySetBitCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n /= 2;
    }
    return count;
}

bool cmp(int a, int b)
{
    int count1 = sortBySetBitCount(a);
    int count2 = sortBySetBitCount(b);
    if (count1 <= count2)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stable_sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
