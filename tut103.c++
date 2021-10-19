/*Add 1 to a number represented as linked list -> A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.
Example 1:
Input:
LinkedList: 4->5->6
Output: 4->5->7

Example 2:
Input:
LinkedList: 1->2->3
Output: 1->2->4 
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    // Node(int data)
    // {
    //     this->data = data;
    //     this->next = NULL;
    // }
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

Node *addOne(Node *head)
{
    Node *curr = head;
    Node *last = head;

    int flag = 0, cnt = 0;
    while (curr)
    {
        if (curr->data != 9)
        {
            last = curr;
            cnt++;
        }
        else
        {
            flag = 1;
        }
        curr = curr->next;
    }

    if (flag == 0)
    {
        last->data++;
        return head;
    }

    if (cnt != 0)
    {
        last->data++;
        last = last->next;
        while (last)
        {
            last->data = 0;
            last = last->next;
        }
        return head;
    }

    while (last)
    {
        last->data = 0;
        last = last->next;
    }

    Node *t = newNode(1);
    t->next = head;
    head = t;

    return head;
}

int main()
{

    Node *head = newNode(4);
    head->next = newNode(5);
    head->next->next = newNode(7);

    cout << "Linked list before adding 1\n";
    printLinkedList(head);

    head = addOne(head);

    cout << "\nLinked list after adding 1\n";
    printLinkedList(head);

    return 0;
}