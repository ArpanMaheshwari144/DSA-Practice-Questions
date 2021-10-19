/*Top View of Binary Tree -> Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree
       1
    /     \
   2       3
  /  \    /   \
4    5  6      7
Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.
Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
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
void topViewFind(Node *root, int height, int hd, map<int /*hd of root*/, pair<int /*root data*/, int /*level*/>> &m)
{
    if (root == NULL)
    {
        return;
    }

    // If this condition is true then make a new entry with that key as the key doesn't exist in the map
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root->data, height); // height represents level
    }
    else
    {
        pair<int, int> p = (m.find(hd))->second;

        // for top view -> height<p.second
        if (height < p.second)
        {
            m.erase(hd);
            m[hd] = make_pair(root->data, height);
        }
    }

    // Horizontal distance of a left child = horizontal distance of its parent - 1.
    topViewFind(root->left, height + 1, hd - 1, m);

    // Horizontal distance of a right child = horizontal distance of its parent + 1.
    topViewFind(root->right, height + 1, hd + 1, m);
}

void topView(struct Node *root)
{
    map<int, pair<int, int>> m;
    topViewFind(root, 0, 0, m);

    // By default, a Map in C++ is sorted in increasing order based on its key
    // cout << "Top view will be: " << endl;
    // for (map<int, pair<int, int>>::iterator it = m.begin(); it != m.end(); it++)
    // {
    //     cout << "Key is: " << it->first << " and corressponding pair:" << (it->second).first << "," << (it->second).second << endl;
    // }

    // By default, a Map in C++ is sorted in increasing order based on its key
    cout << "Top view will be: ";
    for (map<int, pair<int, int>>::iterator it = m.begin(); it != m.end(); it++)
    {
        pair<int, int> p = it->second;
        cout << p.first << " ";
    }
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    topView(root);

    return 0;
}