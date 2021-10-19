/*Check if all levels of two trees are anagrams or not -> Given two binary trees, we have to check if each of their levels are anagrams of each other or not.

Example:

 Tree 1               Tree 2
    1                   1
   / \                 / \
  3   2               2   3
    /  \            /  \
   5   4           4   5

Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5
As we can clearly see all the levels of above two binary trees are anagrams of each other, hence return true.
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

bool areAnagrams(Node *root1, Node *root2)
{
    // Base Cases
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);

    while (true)
    {
        int n1 = q1.size(), n2 = q2.size();

        // If n1 and n2 are different
        if (n1 != n2)
        {
            return false;
        }

        // If level order traversal is over
        if (n1 == 0)
        {
            break;
        }

        vector<int> v1, v2;
        while (n1 > 0)
        {
            Node *node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
            {
                q1.push(node1->left);
            }
            if (node1->right != NULL)
            {
                q1.push(node1->right);
            }
            n1--;

            Node *node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
            {
                q2.push(node2->left);
            }
            if (node2->right != NULL)
            {
                q2.push(node2->right);
            }
            v1.push_back(node1->data);
            v2.push_back(node2->data);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if (v1 != v2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Tree 1
    Node *root1 = createNode(1);
    root1->left = createNode(3);
    root1->right = createNode(2);
    root1->right->left = createNode(5);
    root1->right->right = createNode(4);

    // Tree 2
    Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    bool ans = areAnagrams(root1, root2);
    if (ans == true)
    {
        cout << "Anagrams";
    }
    else
    {
        cout << "Not Anagrams";
    }

    return 0;
}