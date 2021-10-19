/*Print all k-sum paths in a binary tree -> A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.
Examples:
Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
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

void printPath(vector<int> &v, int index)
{
    // we printing top to bottom
    for (int i = index; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printKPathUtil(Node *root, vector<int> &v, int k)
{
    if (root == NULL)
    {
        return;
    }

    // Pre-Order traversal
    v.push_back(root->data);
    printKPathUtil(root->left, v, k);
    printKPathUtil(root->right, v, k);

    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        sum += v[i];
        if (sum == k)
        {
            printPath(v, i);
        }
    }
    v.pop_back(); // it is no more part of the path
}

void printKPath(Node *root, int k)
{
    vector<int> v;
    printKPathUtil(root, v, k);
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(3);
    root->left->left = createNode(2);
    root->left->right = createNode(1);
    root->left->right->left = createNode(1);
    root->right = createNode(-1);
    root->right->left = createNode(4);
    root->right->left->left = createNode(1);
    root->right->left->right = createNode(2);
    root->right->right = createNode(5);
    root->right->right->right = createNode(6);

    int k = 5;
    printKPath(root, k);

    return 0;
}