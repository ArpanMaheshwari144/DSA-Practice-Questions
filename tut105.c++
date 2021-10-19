/*Split a Circular Linked List into two halves -> Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.
Example 1:
Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
Example 2:
Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5
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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (head == NULL)
    {
        return;
    }
    Node *slow = head;
    Node *fast = head;

    // It is a circular linkedlist we sholud compare with head
    while (fast->next != head && fast->next->next != head) // if linkedlist size is odd or even both
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next->next == head)
    {
        fast = fast->next;
    }
    *head1_ref = head; // pointing to the fast half
    if (head->next != head)
    {
        *head2_ref = slow->next; // pointing to the second half
    }
    fast->next = slow->next; // second half circular
    slow->next = head;       // first half circular
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

int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    // This will create a circular linked list like this 12->56->2->11
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    cout << "Original Circular Linked List: ";
    printLinkedList(head);

    /* Split the list */
    splitList(head, &head1, &head2);

    cout << "\nFirst Circular Linked List: ";
    printLinkedList(head1);

    cout << "\nSecond Circular Linked List: ";
    printLinkedList(head2);

    return 0;
}