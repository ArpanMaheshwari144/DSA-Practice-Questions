/*Flattening a Linked List -> Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
Example 1:
Input:
5 -> 10 -> 19 -> 28
|    |     |     | 
7    20    22   35
|          |     | 
8          50   40
|                | 
30              45
Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Note: | represents the bottom pointer.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *bottom;
};

void push(Node **head_ref, int data)
{
    Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = NULL;

    new_node->data = data;

    new_node->bottom = (*head_ref);

    (*head_ref) = new_node;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->bottom;
    }
}

// 'compare' function used to build up the priority queue
struct compare
{
    bool operator()(struct Node *t1, struct Node *t2)
    {
        return t1->data > t2->data;
    }
};

Node *flatten(Node *root)
{
    Node *t = root;
    Node *head = NULL;

    priority_queue<Node *, vector<Node *>, compare> pq;

    // In this loop we are pushing all the main nodes
    while (t != NULL)
    {
        pq.push(t);
        t = t->next;
    }

    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();

        if (temp->bottom != NULL)
        {
            pq.push(temp->bottom);
        }

        // we will create a new linked list
        if (head == NULL)
        {
            head = temp;
            t = temp;
            t->next = NULL;
        }
        else
        {
            t->bottom = temp;
            t = temp;
            t->next = NULL;
        }
    }
    return head;
}

int main()
{
    Node *head = NULL;

    push(&head, 28);
    push(&head, 19);
    push(&head, 10);
    push(&head, 5);

    push(&(head->next), 30);
    push(&(head->next), 8);
    push(&(head->next), 7);

    push(&(head->next->next), 20);

    push(&(head->next->next->next), 50);
    push(&(head->next->next->next), 22);

    push(&(head->next->next->next->next), 45);
    push(&(head->next->next->next->next), 40);
    push(&(head->next->next->next->next), 35);

    head = flatten(head);

    printLinkedList(head);

    return 0;
}