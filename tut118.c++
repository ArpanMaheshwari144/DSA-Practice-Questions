/*Kth ancestor of a node in binary tree -> Given a binary tree in which nodes are numbered from 1 to n. Given a node and a positive integer K. We have to print the Kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then print -1.
For example in the below given binary tree, 2nd ancestor of node 4 and 5 is 1. 3rd ancestor of node 4 will be -1.
              1
             / \
            2   3
           / \
          4   5
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
    Node *temp;

    // Allocating memory in the heap
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Set the data
    temp->data = data;

    // Set the left and right children to NULL
    temp->left = NULL;
    temp->right = NULL;

    // Finally return the created node
    return temp;
}

Node *kthAncestor(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node || kthAncestor(root->left, k, node) || kthAncestor(root->right, k, node))
    {
        if (k > 0)
        {
            k--;
        }
        else if (k == 0)
        {
            cout << "kth ancestor is: " << root->data;
            return NULL;
        }
        return root;
    }
    return NULL;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right = createNode(3);

    int k = 1; // kth ancestor of given node
    int node = 5;

    Node *ans = kthAncestor(root, k, node);

    if (ans)
    {
        cout << "-1";
    }

    return 0;
}