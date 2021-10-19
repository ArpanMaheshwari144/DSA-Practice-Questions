/*Deletion from a Circular Linked List -> We will be given a node and our task is to delete that node from the circular linked list.
Examples: 
Input : 2->5->7->8->10->(head node)
data = 5
Output : 2->7->8->10->(head node)

Input : 2->5->7->8->10->(head node)
data = 7
Output : 2->5->8->10->2(head node)
Algorithm
Case 1: List is empty -> If the list is empty we will simply return.
Case 2:List is not empty:
If the list is not empty then we define two pointers curr and prev and initialize the pointer curr with the head node.
Traverse the list using curr to find the node to be deleted and before moving curr to next node, everytime set prev = curr.
If the node is found, check if it is the only node in the list. If yes, set head = NULL and free(curr).
If the list has more than one node, check if it is the first node of the list. Condition to check this( curr == head). If yes, then move prev until it reaches the last node. After prev reaches the last node, set head = head -> next and prev -> next = head. Delete curr.
If curr is not first node, we check if it is the last node in the list. Condition to check this is (curr -> next == head).
If curr is the last node. Set prev -> next = head and delete the node curr by free(curr).
If the node to be deleted is neither the first node nor the last node, then set prev -> next = temp -> next and delete curr.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printLinkedList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then
       set the next of last node */
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}

void deleteNode(Node **head, int key)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        head = NULL;
        return;
    }

    Node *last = *head, *d;
    if ((*head)->data == key)
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
    {
        cout << "No such key is found";
    }
}

int main()
{
    Node *head = NULL;

    /* Created linked list will be 2->5->7->8->10 */
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    cout << "Linked List Before Deletion: ";
    printLinkedList(head);

    deleteNode(&head, 7);

    cout << "\nLinked List After Deletion: ";
    printLinkedList(head);

    return 0;
}