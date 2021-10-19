/*Convert a normal BST to Balanced BST -> Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.
Examples :
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7
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

// unbalaced BST -> inorder traversal which will make sorted and store it into a vector
void storeBSTElements(Node *root, vector<Node *> &v)
{
    if (root == NULL)
    {
        return;
    }

    storeBSTElements(root->left, v);
    v.push_back(root);
    storeBSTElements(root->right, v);
}

Node *buildTreeUtil(vector<Node *> v, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = v[mid];

    root->left = buildTreeUtil(v, start, mid - 1);
    root->right = buildTreeUtil(v, mid + 1, end);

    return root;
}

Node *buildTree(Node *root)
{
    vector<Node *> v;
    storeBSTElements(root, v);

    int n = v.size();
    return buildTreeUtil(v, 0, n - 1);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(8);
    root->left->left = createNode(7);
    root->left->left->left = createNode(6);
    root->left->left->left->left = createNode(5);

    root = buildTree(root);

    printf("Preorder traversal of balanced BST is: ");
    preOrder(root);

    return 0;
}