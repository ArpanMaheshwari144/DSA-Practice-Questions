/*In-Place Merge Sort -> Implement Merge Sort i.e. standard implementation keeping the sorting algorithm as in-place.
In-place means it does not occupy extra memory for merge operation as in standard case.
Examples:
Input: arr[] = {2, 3, 4, 1}
Output: 1 2 3 4
Input: arr[] = {56, 2, 45}
Output: 2 45 56
*/
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int start1 = mid + 1;

    if (arr[mid] <= arr[start1])
    {
        return;
    }

    while (start <= mid && start1 <= end)
    {
        if (arr[start] <= arr[start1])
        {
            start++;
        }
        else
        {
            int value = arr[start1];
            int index = start1;

            // Shift all the elements between element 1 element 2, right by 1.
            while (index != start)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
            start++;
            mid++;
            start1++;
        }
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}