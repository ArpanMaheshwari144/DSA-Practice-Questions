/*Weighted Job Scheduling in O(n Log n) time -> Given N jobs where every job is represented by following three elements of it.
1. Start Time
2. Finish Time
3. Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Example:
Input: Number of Jobs n = 4
Job Details {Start Time, Finish Time, Profit}
Job 1:  {1, 2, 50} 
Job 2:  {3, 5, 20}
Job 3:  {6, 19, 100}
Job 4:  {2, 100, 200}
Output: The maximum profit is 250.
We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250. */

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

bool compare(Job j1, Job j2)
{
    return (j1.finish < j2.finish);
}

int binarySearch(Job jobs[], int index)
{
    int low = 0, high = index - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int findMaxProfit(Job a[], int n)
{
    sort(a, a + n, compare);

    int maxProfit[n];
    maxProfit[0] = a[0].profit;

    for (int i = 1; i < n; i++)
    {
        int includeProfit = a[i].profit; // for accessing the structure elements we use .(dot) operator
        int x = binarySearch(a, i);
        if (x != -1)
        {
            includeProfit += maxProfit[x];
        }
        maxProfit[i] = max(includeProfit, maxProfit[i - 1]); // maxProfit[i-1] is excluded profit
    }
    return maxProfit[n - 1];
}

int main()
{
    Job a[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Optimal profit is " << findMaxProfit(a, n);

    return 0;
}