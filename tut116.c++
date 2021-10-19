/*Bottom View of Binary Tree -> Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.
      20
     /  \
    8    22
   / \     \
  5   3     25
     / \      
    10  14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.
        20
       /  \
     8     22
    / \   /  \
   5   3 4   25
      /   \      
     10    14

For the above tree the output should be 5 10 4 14 25.
Example 1:
Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.Thus nodes of the binary tree will be printed as such 3 1 2.

Example 2:
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
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

// hd as horizontal distance
// Horizontal distance of the root = 0.
// Horizontal distance of a left child = horizontal distance of its parent - 1.
// Horizontal distance of a right child = horizontal distance of its parent + 1.
void bottomViewFind(Node *root, int height, int hd, map<int /*hd of root*/, pair<int /*root data*/, int /*level*/>> &m)
{
    if (root == NULL)
    {
        return;
    }

    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root->data, height); // height represents level
    }
    else
    {
        pair<int, int> p = (m.find(hd))->second;

        // for bottom view -> height>=p.second
        if (height >= p.second)
        {
            m.erase(hd);
            m[hd] = make_pair(root->data, height);
        }
    }

    // Horizontal distance of a left child = horizontal distance of its parent - 1.
    bottomViewFind(root->left, height + 1, hd - 1, m);

    // Horizontal distance of a right child = horizontal distance of its parent + 1.
    bottomViewFind(root->right, height + 1, hd + 1, m);
}

vector<int> bottomView(Node *root, vector<int> &v)
{
    map<int, pair<int, int>> m;
    bottomViewFind(root, 0, 0, m);

    // By default, a Map in C++ is sorted in increasing order based on its key.
    for (map<int, pair<int, int>>::iterator it = m.begin(); it != m.end(); it++)
    {
        pair<int, int> p = it->second;
        v.push_back(p.first);
    }
    return v;
}

int main()
{
    Node *root = createNode(20);
    root->left = createNode(8);
    root->left->left = createNode(5);
    root->left->right = createNode(3);
    root->left->right->left = createNode(10);
    root->right = createNode(22);
    root->right->left = createNode(4);
    root->right->left->right = createNode(14);
    root->right->right = createNode(25);

    vector<int> v;
    v = bottomView(root, v);

    cout << "Bottom view will be: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}