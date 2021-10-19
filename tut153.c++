/*Convert BST to Min Heap -> Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Min Heap. 

Examples: 
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

The given BST has been transformed into a Min Heap.
All the nodes in the Min Heap satisfies the given
condition, that is, values in the left subtree of
a node should be less than the values in the right
subtree of the node. 
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

void inorderTraversal(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void bstToMinHeap(Node *root, vector<int> arr, int &index)
{
    if (root == NULL)
    {
        return;
    }

    root->data = arr[index];
    index++;
    bstToMinHeap(root->left, arr, index);
    bstToMinHeap(root->right, arr, index);
}

void preoderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preoderTraversal(root->left);
    preoderTraversal(root->right);
}

int main()
{
    Node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    int index = 0;
    vector<int> arr;

    inorderTraversal(root, arr);
    bstToMinHeap(root, arr, index);
    preoderTraversal(root);

    return 0;
}