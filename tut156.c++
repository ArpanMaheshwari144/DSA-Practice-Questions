/*Convert min Heap to max Heap -> Given array representation of min Heap, convert it to max Heap in O(n) time.

Example: 
Input: arr[] = [3 5 9 6 8 20 10 12 18 9]

          3
       /    \
      5       9
    /  \    /  \
   6    8  20   10
 /  \    /
12   18 9 


Output: arr[] = [20 18 10 12 9 9 3 5 6 8] OR [any Max Heap formed from input elements]

         20
       /    \
     18      10
   /    \    /  \
  12     9  9    3
 /  \   /
5    6 8 
*/

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

void convertMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Min Heap array : ");
    printArray(arr, n);

    convertMaxHeap(arr, n);

    printf("\nMax Heap array : ");
    printArray(arr, n);

    return 0;
}