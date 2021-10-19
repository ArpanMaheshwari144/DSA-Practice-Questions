/*Find largest subtree sum in a tree -> Given a binary tree, task is to find subtree with maximum sum in tree.
Examples:
Input:
       1
     /   \
    2      3
   / \    / \
  4   5  6   7
Output: 28
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Input:
       1
     /    \
   -2      3
   / \    /  \
  4   5  -6   2
Output : 7
Subtree with largest sum is:  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.
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

int findLargestSubtreeSum(Node *root, int &ans)
{
    if (!root)
    {
        return 0;
    }

    int currentSum = root->data + findLargestSubtreeSum(root->left, ans) + findLargestSubtreeSum(root->right, ans);

    ans = max(ans, currentSum);

    return currentSum;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(-2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(-6);
    root->right->right = createNode(2);

    int ans = INT_MIN;

    ans = findLargestSubtreeSum(root, ans);

    cout << "The largest subtree sum is: " << ans;

    return 0;
}