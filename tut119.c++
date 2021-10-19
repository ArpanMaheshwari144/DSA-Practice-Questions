/*Minimum swap required to convert binary tree to binary search tree -> Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.
Examples:  
Input : arr[] = {5, 6, 7, 8, 9, 10, 11}
Output : 3
Binary tree of the given array:
        5
      /   \
     6     7
    / \   / \
   8   9 10  11
Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.
       8
     /   \
    6    10
   / \   / \
  5   7 9  11
So, minimum 3 swaps are required.
*/

#include <bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inOrderTraversal(int a[], vector<int> &v, int n, int index)
{
    // if index is greater or equal to vector size
    if (index >= n)
    {
        return;
    }
    inOrderTraversal(a, v, n, 2 * index + 1);

    // push elements in vector
    v.push_back(a[index]);
    cout << a[index] << " ";
    inOrderTraversal(a, v, n, 2 * index + 2);
}

// Function to find minimum swaps to sort an array
int minSwaps(vector<int> &v)
{
    vector<pair<int, int>> t(v.size());
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        t[i].first = v[i];
        t[i].second = i;
    }

    sort(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++)
    {
        // second element is equal to i
        if (i == t[i].second)
            continue;
        else
        {
            // swaping of elements
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        // Second is not equal to i
        if (i != t[i].second)
        {
            --i;
        }
        ans++;
    }
    return ans;
}

int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    inOrderTraversal(a, v, n, 0);
    // cout << minSwaps(v) << endl;

    return 0;
}