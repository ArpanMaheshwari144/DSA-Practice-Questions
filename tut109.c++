/*Rotate Doubly linked list by N nodes -> Given a doubly linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list.
Examples:
Input : a  b  c  d  e   N = 2
Output : c  d  e  a  b 
Input : a  b  c  d  e  f  g  h   N = 4
Output : e  f  g  h  a  b  c  d
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

void printLinkedList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " "
             << "<=>"
             << " ";
        head = head->next;
    }
    cout << head->data;
}

void rotate(Node **head, int N)
{
    if (N == 0)
    {
        return;
    }

    Node *current = *head;
    for (int i = 1; i < N; i++)
    {
        current = current->next;
    }

    Node *nthNode = current;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *head;   // last node connected to head
    (*head)->prev = current; // head is connected to last node
    (*head) = nthNode->next; // nthNode becomes a new head
    nthNode->next = NULL;
    (*head)->prev = NULL;
}

int main()
{
    Node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    int N = 2;

    cout << "Given linked list \n";
    printLinkedList(head);

    rotate(&head, N);

    cout << "\nRotated Linked list \n";
    printLinkedList(head);

    return 0;
}