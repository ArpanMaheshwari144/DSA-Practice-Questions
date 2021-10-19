/*Find first node of loop in a linked list -> Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. If the loop is present then it returns point to the first node of the loop. Else it returns NULL.*/
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

Node *detectLoop(Node *head)
{
    // creating a temporary node
    Node *temp = new Node; // this will call Node default constructor
    while (head != NULL)
    {
        if (head->next == NULL)
        {
            return NULL;
        }
        if (head->next == temp)
        {
            break;
        }

        Node *nex = head->next;
        head->next = temp;
        head = nex;
    }
    return head;
}
int main()
{
    Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    Node *res = detectLoop(head);
    if (res == NULL)
    {
        cout << "Loop does not exist";
    }
    else
    {
        cout << "Loop starting node is " << res->data;
    }
    return 0;
}