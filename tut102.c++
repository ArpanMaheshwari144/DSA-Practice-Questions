/*Move last element to front of a given Linked List -> Write a function that moves the last element to the front in a given Singly Linked List. For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void moveToFront(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *secondLast = temp;
    Node *last = temp->next;
    secondLast->next = NULL;
    last->next = *head;
    *head = last;
}

int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    cout << "Linked list before moving last to front\n";
    printLinkedList(head);

    moveToFront(&head);

    cout << "\nLinked list after removing last to front\n";
    printLinkedList(head);

    return 0;
}