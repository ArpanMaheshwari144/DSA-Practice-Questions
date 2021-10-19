/*Check if Linked List is Palindrome -> Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse(Node *head)
{
    Node *curr = head, *next = NULL, *prev = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    Node *slow = head, *fast = head;

    // finding middle we should always use tortoise and hare method
    while (fast->next && fast->next->next)
    { // this will help when linkedlis size both odd and even
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow will point to the middle of the linked list
    slow->next = reverse(slow->next); // reverse right half
    slow = slow->next;                // moved to the right half

    while (slow)
    {
        if (head->data != slow->data)
        {
            return 0;
        }

        head = head->next;
        slow = slow->next;
    }
    return 1;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    bool res = isPalindrome(head);

    if (res)
    {
        cout << "LinkedList is Palindrome" << endl;
    }
    else
    {
        cout << "LinkedList is not Palindrome" << endl;
    }

    return 0;
}