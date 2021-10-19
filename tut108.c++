/*Count triplets in a sorted doubly linked list whose sum is equal to a given value x -> Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.
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

int countPairs(Node *front, Node *back, int x)
{
    int count = 0;

    // two pointers approach
    while (front != NULL && back != NULL && front != back && back->next != front)
    {
        if (front->data + back->data == x)
        {
            count++;
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
    return count;
}

int countTriplets(Node *head, int x)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *curr;
    Node *front;
    Node *back = head;
    int count = 0;

    while (back->next != NULL)
    {
        back = back->next;
    }

    curr = head;
    while (curr != NULL)
    {
        front = curr->next;

        count += countPairs(front, back, x - curr->data);

        curr = curr->next;
    }
    return count;
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

    int x = 17;

    cout << "Total pairs is: " << countTriplets(head, x);

    return 0;
}