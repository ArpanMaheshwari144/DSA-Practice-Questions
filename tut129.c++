/*Flatten BST to sorted list | Increasing order -> Given a binary search tree, the task is to flatten it to a sorted list. Precisely, the value of each node must be lesser than the values of all the nodes at its right, and its left node must be NULL after flattening. We must do it in O(H) extra space where ‘H’ is the height of BST.

Examples:
Input: 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
Output: 2 3 4 5 6 7 8
Input:
      1
       \
        2
         \
          3
           \
            4
             \
              5
Output: 1 2 3 4 5
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printNodes(Node *parent)
{
    Node *curr = parent;
    while (curr != NULL)
    {
        cout << curr->data << " ", curr = curr->right;
    }
}

void inorder(Node *curr, Node *&prev)
{
    // Base case
    if (curr == NULL)
    {
        return;
    }
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

// Function to flatten binary tree using
// level order traversal
Node *flatten(Node *parent)
{
    // Dummy node
    Node *dummy = new Node(-1);

    // Pointer to previous element
    Node *prev = dummy;

    // Calling in-order traversal
    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    Node *ret = dummy->right;

    // Delete dummy node
    delete dummy;
    return ret;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Calling required function
    Node *n = flatten(root);
    printNodes(n);

    return 0;
}