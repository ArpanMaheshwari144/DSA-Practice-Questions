/*Sort a k sorted doubly linked list -> Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.
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

// 'compare' function used to build up the priority queue
struct compare
{
    bool operator()(struct Node *t1, struct Node *t2)
    {
        return t1->data > t2->data;
    }
};

Node *sortAKSortedDLL(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    // priority_queue 'pq' implemented as min heap with the help of 'compare' function
    // Declaration of MinHeap
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *newHead = NULL;
    Node *last = NULL;

    for (int i = 0; i <= k && head != NULL; i++)
    {
        pq.push(head);

        head = head->next;
    }

    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }

        pq.pop();

        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }

    last->next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;

    // Create the doubly linked list: 3<->6<->2<->12<->56<->8
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);

    int k = 2;

    cout << "Original Doubly linked list: ";
    printLinkedList(head);

    // sort the biotonic DLL
    head = sortAKSortedDLL(head, k);

    cout << "\nDoubly linked list after sorting: ";
    printLinkedList(head);

    return 0;
}