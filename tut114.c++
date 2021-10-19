/*Create a mirror tree from the given binary tree -> Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.
Examples:
Input:                               
        5
       / \
      3   6
     / \
    2   4
Output:
Original tree: 2 3 4 5 6 
Mirror tree will be:
      5
     / \
    6   3
       / \
      4   2
Mirror tree: 6 5 4 3 2
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

void mirrorify(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Postorder traversal
    mirrorify(root->left);
    mirrorify(root->right);
    swap(root->left, root->right);
}

// printing in inorder traversal
void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main()
{
    Node *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);

    cout << "Original tree: ";
    printTree(root);

    mirrorify(root);

    cout << "\nMirror tree: ";
    printTree(root);

    return 0;
}