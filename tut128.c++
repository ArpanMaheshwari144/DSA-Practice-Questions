/*Replace every element with the least greater element on its right Given an array of integers, replace every element with the least greater element on its right side in the array. If there are no greater element on the right side, replace it with -1.

Examples: 
Input: [8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28]
Output: [18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1]
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    // Creating a node pointer
    struct Node *temp;

    // Allocating memory in the heap
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Set the data
    temp->data = data;

    // Set the left and right children to NULL
    temp->left = NULL;
    temp->right = NULL;

    // Finally return the created node
    return temp;
};

// Inorder successor
void insert(Node *&node, int val, Node *&succ)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
    {
        node = createNode(val);
    }

    // If key is smaller than root's key, go to left subtree and set successor as current node
    if (val < node->data)
    {
        succ = node;
        insert(node->left, val, succ);
    }

    // go to right subtree
    else if (val > node->data)
    {
        insert(node->right, val, succ);
    }
}

int main()
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = NULL;

    // start from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;

        // insert current element into BST and find its inorder successor
        insert(root, arr[i], succ);

        // replace element by its inordersuccessor in BST
        if (succ != NULL)
        {
            arr[i] = succ->data;
        }
        else // No inorder successor
        {
            arr[i] = -1;
        }
    }

    cout << "After replace every element with the least greater element on its right: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}