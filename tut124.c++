/*Insert in a Binary Search Tree*/
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

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void insertElement(Node *root, int elementToBeInserted)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (elementToBeInserted == root->data)
        {
            printf("\nCannot insert %d, it is already present in binary search tree ", elementToBeInserted);
            return;
        }
        else if (elementToBeInserted < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *ptr = createNode(elementToBeInserted);
    if (elementToBeInserted < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
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

    if (root == NULL)
    {
        printf("There is no elements in a binary search tree");
        exit(0);
    }
    int elementToBeInserted = 16;

    cout << "Before inserting the new element: ";
    inOrderTraversal(root);
    insertElement(root, elementToBeInserted);
    cout << "\nAfter inserting the new element: ";
    inOrderTraversal(root);

    return 0;
}