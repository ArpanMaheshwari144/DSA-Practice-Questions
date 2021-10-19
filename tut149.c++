/*Interleave the first half of the queue with second half -> Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
Only a stack can be used as an auxiliary space.

Examples:
Input :  1 2 3 4
Output : 1 3 2 4
Explanation:
first half of the queue - 1 2
second half of the queue - 3 4
output should be -> (first half queue element) (second half queue element) (first half queue element) and so-on
output - 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
*/

#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    stack<int> s;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // add the elements to the back of the queue from the stack
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // dequeue the first half elements of queue and enqueue them back
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Push first half elements into the stack
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // interleave the elements of queue and stack
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}