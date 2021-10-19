/*Find pairs with given sum in doubly linked list -> Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in doubly linked list whose sum is equal to given value x, without using any extra space ? 
Example:  
Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
x = 7
Output: (6, 1), (5,2)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

void push(Node **head_ref, int data)
{
    Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void pairSum(Node *head, int x)
{
    Node *front = head;
    Node *back = head;
    int count = 0;
    bool found = false;

    while (back->next != NULL)
    {
        back = back->next;
    }

    // two pointers approach
    while (front != NULL && back != NULL && front != back && back->next != front)
    {
        if (front->data + back->data == x)
        {
            count++;
            found = true;
            cout << "(" << front->data << ", " << back->data << ")" << endl;
            front = front->next;
            back = back->prev;
        }
        else if (front->data + back->data > x)
        {
            back = back->prev;
        }
        else
        {
            front = front->next;
        }
    }

    if (found == false)
    {
        cout << "No pair found" << endl;
    }

    cout << "Total pair is: " << count << endl;
}

int main()
{
    Node *head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);

    int x = 7;

    pairSum(head, x);

    return 0;
}