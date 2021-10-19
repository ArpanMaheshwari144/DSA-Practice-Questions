/*Reverse a doubly linked list in groups of given size -> Given a doubly linked list containing n nodes. The problem is to reverse every group of k nodes in the list.
Example:
Input: 10<=>8<=>4<=>2
k = 2
Output: 8<=>10<=>2<=>4
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

Node *reverseListInGroupOfGivenSize(Node *head, int k)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    int count = 0;
    while (count < k && curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseListInGroupOfGivenSize(next, k);
    }
    return prev;
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

int main()
{
    Node *head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    int k = 2;

    cout << "Original list: ";
    printLinkedList(head);

    head = reverseListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printLinkedList(head);

    return 0;
}
