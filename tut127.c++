/*Find median of BST in O(n) time and O(1) space. Given a Binary Search Tree, find median of it.
If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
If no. of nodes are odd : then median = (n+1)/2th node.
For example
Given BST(with odd no. of nodes) is : 
                   6
                 /   \
                3     8
              / \    / \
             1  4   7   9

Inorder of Given BST will be : 1, 3, 4, 6, 7, 8, 9
So, here median will 6.

Given BST(with even no. of nodes) is :  
                    6
                  /   \
                 3     8
               / \   /  
              1   4 7    

Inorder of Given BST will be : 1, 3, 4, 6, 7, 8
So, here median will  (4+6)/2 = 5.
*/

#include <bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
struct Node *insert(struct Node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Function to count nodes in a binary search tree using Morris Inorder traversal*/
int counNodes(struct Node *root)
{
    struct Node *current, *pre;

    // Initialise count of nodes as 0
    int count = 0;

    if (root == NULL)
        return count;

    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // Count node if its left is NULL
            count++;

            // Move to its right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;

            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in if part to restore the original tree i.e., fix 
			the right child of predecssor */
            else
            {
                pre->right = NULL;

                // Increment count if the current node is to be visited
                count++;
                current = current->right;
            }
        }
    }

    return count;
}

/* Function to find median in O(n) time and O(1) space using Morris Inorder traversal*/
int findMedian(struct Node *root)
{
    if (root == NULL)
        return 0;

    int count = counNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;

            // check if current node is the median Odd case
            if (count % 2 != 0 && currCount == (count + 1) / 2)
                return prev->data;

            // Even case
            else if (count % 2 == 0 && currCount == (count / 2) + 1)
                return (prev->data + current->data) / 2;

            // Update prev for even no. of nodes
            prev = current;

            //Move to the right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in if part to restore the original tree i.e., fix the right child of predecssor */
            else
            {
                pre->right = NULL;
                prev = pre;

                // Count current node
                currCount++;

                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count + 1) / 2)
                    return current->data;

                else if (count % 2 == 0 && currCount == (count / 2) + 1)
                    return (prev->data + current->data) / 2;

                // update prev node for the case of even no. of nodes
                prev = current;
                current = current->right;
            }
        }
    }
    return 0;
}

int main()
{

    /* Let us create following BST 
		   50 
		 /    \ 
		30	  70 
	  /  \   /  \ 
	20  40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Median of BST is " << findMedian(root);
    return 0;
}
