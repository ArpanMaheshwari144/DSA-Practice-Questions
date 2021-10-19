/*Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.*/

#include <iostream>
using namespace std;

long long int ans = 0;
void merge(long long int a[], long long int low, long long int mid, long long int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    long long int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = a[i + low];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = a[i + mid + 1];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            ans += n1 - i; // extra line which is not include in merge sort
            a[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        a[k++] = L[i++];
    }

    while (j < n2)
    {
        a[k++] = R[j++];
    }
}

void mergeSort(long long int a[], long long int low, long long int high)
{
    if (low < high)
    {
        long long int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
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
    mergeSort(a, 0, n - 1);

    cout << ans << " ";

    return 0;
}