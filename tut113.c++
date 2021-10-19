/*Multiply two linked lists -> Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 
Note: The output could be large take modulo 10^9+7.
Input : 9->4->6
        8->4
Output : 79464
Input : 3->2->1
        1->2
Output : 3852
*/
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

void push(Node **head_ref, int new_data)
{
    // allocate node
    Node *new_node = newNode(new_data);

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

/*s = "123" given string so we convert this to interger?
int num = 0, num = (num*10) + int(s[i])
num = 0
num = 0 * 10 + 1 = 1
num = 1 * 10 + 2 = 12
num = 12 * 10 + 3 = 123
*/

/* Modular Arithemetic Formula-
Rule for modular addition is: (a + b) mod m = ((a mod m) + (b mod m)) mod m
Rule for modular multiplication is: (a x b) mod m = ((a mod m) x (b mod m)) mod m
*/
long multiplyTwoLists(Node *l1, Node *l2)
{
    long int ans1 = 0, ans2 = 0, mod = 1000000007;
    while (l1 || l2)
    {
        if (l1)
        {
            ans1 = ((ans1 % mod * 10 % mod) % mod + l1->data % mod) % mod;
            l1 = l1->next;
        }
        if (l2)
        {
            ans2 = ((ans2 % mod * 10 % mod) % mod + l2->data % mod) % mod;
            l2 = l2->next;
        }
    }
    return (ans1 % mod * ans2 % mod) % mod;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *first = NULL;
    Node *second = NULL;

    // create first list 9->4->6
    push(&first, 0);
    push(&first, 0);
    push(&first, 1);
    printf("First Linked List is: ");
    printLinkedList(first);

    // create second list 8->4
    push(&second, 0);
    push(&second, 1);
    printf("Second Linked List is: ");
    printLinkedList(second);

    // Multiply the two lists and see result
    cout << "After multiplying the result is: ";
    cout << multiplyTwoLists(first, second);

    return 0;
}
