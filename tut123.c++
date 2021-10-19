/*Search in a Binary Search Tree*/
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

Node *searchElement(Node *root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchElement(root->left, key);
    }
    else
    {
        return searchElement(root->right, key);
    }
    return 0;
}

int main()
{
    Node *root = createNode(5);
    root->left = createNode(3);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right = createNode(9);
    root->right->right = createNode(10);
    root->right->left = createNode(6);

    Node *ans = searchElement(root, 10);
    if (ans != NULL)
    {
        printf("Found: %d ", ans->data);
    }
    else
    {
        printf("Element is not present");
    }

    return 0;
}