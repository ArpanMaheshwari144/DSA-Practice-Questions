// Rearrange array in alternating positive & negative items with O(1) extra space

#include <iostream>
using namespace std;

long long int ans = 0;

void change(long long int arr[], long long int n)
{
    int negative = 0, positive = 1, i = 0;

    while (i < n)
    {
        if (arr[i] < 0 && negative < n)
        {
            swap(arr[i], arr[negative]);
            negative += 2;
        }
        i++;
    }
    i = 0;

    while (i < n)
    {
        if (arr[i] >= 0 && positive < n)
        {
            swap(arr[i], arr[positive]);
            positive += 2;
        }
        i++;
    }
}

int main()
{
    long long int n;
    cin >> n;
    long long int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    change(a, n);

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}