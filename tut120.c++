/*Maximum sum of nodes in Binary tree such that no two are adjacent -> Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen node in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take it’s any children in consideration and vice versa. 
Examples: 
         1
        / \
       2   3
      /   / \
     1   4   5
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

void maxSum(Node *root, bool flag1, bool flag2, int &sum1, int &sum2)
{
    if (root == NULL)
    {
        return;
    }

    if (flag1)
    {
        sum1 = max(sum2, sum1 + root->data);
        flag1 = !flag1;
        flag2 = !flag2;
    }
    else if (flag2)
    {
        sum2 = max(sum1, sum2 + root->data);
        flag1 = !flag1;
        flag2 = !flag2;
    }

    maxSum(root->left, flag1, flag2, sum1, sum2);
    maxSum(root->right, flag1, flag2, sum1, sum2);
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(1);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    int sum1 = 0;
    int sum2 = 0;

    maxSum(root, 0, 1, sum1, sum2);

    cout << max(sum1, sum2);

    return 0;
}