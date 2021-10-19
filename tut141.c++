/*GCJ101BB - Picking Up Chicks -> A flock of chickens are running east along a straight, narrow road. Each one is running with its own constant speed. Whenever a chick catches up to the one in front of it, it has to slow down and follow at the speed of the other chick. You are in a mobile crane behind the flock, chasing the chicks towards the barn at the end of the road. The arm of the crane allows you to pick up any chick momentarily, let the chick behind it pass underneath and place the picked up chick back down. This operation takes no time and can only be performed on a pair of chicks that are immediately next to each other, even if 3 or more chicks are in a row, one after the other.
Given the initial locations (Xi) at time 0 and natural speeds (Vi) of the chicks, as well as the location of the barn (B), what is the minimum number of swaps you need to perform with your crane in order to have at least K of the N chicks arrive at the barn no later than time T?
You may think of the chicks as points moving along a line. Even if 3 or more chicks are at the same location, next to each other, picking up one of them will only let one of the other two pass through. Any swap is instantaneous, which means that you may perform multiple swaps at the same time, but each one will count as a separate swap.

Input
The first line of the input gives the number of test cases, C. C test cases follow. Each test case starts with 4 integers on a line -- N, K, B and T. The next line contains the Ndifferent integers Xi, in increasing order. The line after that contains the N integers Vi. All distances are in meters; all speeds are in meters per second; all times are in seconds.

Output
For each test case, output one line containing "Case #x: S", where x is the case number (starting from 1) and S is the smallest number of required swaps, or the word "IMPOSSIBLE".

Limits
1 ≤ C ≤ 100;
1 ≤ B ≤ 1,000,000,000;
1 ≤ T ≤ 1,000;
0 ≤ Xi < B;
1 ≤ Vi ≤ 100;
1 ≤ N ≤ 50;
0 ≤ K ≤ N;

All the Xi's will be distinct and in increasing order.

Example
Input:
3
5 3 10 5
0 2 5 6 7
1 1 1 1 4
5 3 10 5
0 2 3 5 7
2 1 1 1 4
5 3 10 5
0 2 3 4 7
2 1 1 1 4

Output:
Case #1: 0
Case #2: 2
Case #3: IMPOSSIBLE
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k, b, time;
    cout << "Enter number of chicks: ";
    cin >> n;
    cout << "Enter number of chicks you need inside the barn: ";
    cin >> k;
    cout << "Enter co-ordinates of the barn: ";
    cin >> b;
    cout << "Enter time: ";
    cin >> time;

    long long int x[n], v[n], i;
    cout << "Enter the co-ordinates of the chicks: ";
    for (i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter the speed of the chicks: ";
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // count -> how many chicks can reach the barn
    // swaps -> how many time we have to swap slower chick with faster chick
    // not_possible -> how many chicks can never reach the barn
    int count = 0, swaps = 0, not_possible = 0;
    for (i = n - 1; i >= 0; i--)
    {
        int distance_needed = b - x[i];
        int distance_possible = v[i] * time; // distance = speed * time

        if (distance_possible >= distance_needed)
        {
            count++;
            if (not_possible > 0)
            {
                swaps += not_possible;
            }
        }
        else
        {
            not_possible++;
        }

        if (count >= k)
        {
            break;
        }
    }

    if (count >= k)
    {
        cout << swaps;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}