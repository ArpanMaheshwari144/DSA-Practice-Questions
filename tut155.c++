/*Heap Sort -> Heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements.*/

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n)
{
    if (i >= n)
    {
        return;
    }

    int parent = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[parent])
    {
        parent = leftChild; // changing index
    }

    if (rightChild < n && arr[rightChild] > arr[parent])
    {
        parent = rightChild; // changing index
    }

    if (parent != i)
    {
        swap(arr[i], arr[parent]);
        heapify(arr, parent, n);
    }
}

int main()
{
    int arr[] = {4, 10, 3, 5, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Heap Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    // sorting
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }

    // printing the array;
    cout << "\nAfter Heap Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}