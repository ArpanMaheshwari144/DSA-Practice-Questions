/*Construct Binary Tree from String with bracket representation -> Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.
Examples: 
Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Preorder of above tree is "1 2 3".  
Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

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

Node *solve(string s, int &index)
{
    if (index >= s.size())
    {
        return NULL;
    }

    string num = "";
    while (index < s.size() && s[index] != '(' && s[index] != ')')
    {
        num += s[index];
        index++;
    }

    Node *node = new Node(stoi(num)); // stoi -> string to integer
    if (index < s.size() && s[index] == '(')
    {
        index++;
        node->left = solve(s, index);
        index++;
        if (index < s.size() && s[index] == '(')
        {
            index++;
            node->right = solve(s, index);
            index++;
        }
    }
    return node;
}

int main()
{
    string str = "4(2(3)(1))(6(5))";
    int index = 0;
    Node *root = solve(str, index);
    preOrder(root);

    return 0;
}