/*SUBSUMS - Subset Sums -> Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.
Input:
The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.
Output:
Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.
Example:
Input:
3 -1 2
1
-2
3
Output:
5

The following 5 subsets have a sum between -1 and 2:
0 = 0 (the empty subset)
1 = 1
1 + (-2) = -1
-2 + 3 = 1
1 + (-2) + 3 = 2
*/
#include <bits/stdc++.h>
using namespace std;

void generateSubSets(long long int arr[], vector<long long int> &v, int n, int start)
{
    int sum;
    for (int i = 0; i < pow(2, n); i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum = sum + arr[j + start];
            }
        }
        v.push_back(sum);
    }
}

int main()
{
    long long int n, a, b, low, high;
    long long int ans = 0;
    vector<long long int> left, right;
    cin >> n >> a >> b;

    long long int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    generateSubSets(A, left, n / 2, 0);
    generateSubSets(A, right, (n & 1) ? n / 2 + 1 : n / 2, n / 2);

    sort(right.begin(), right.end());

    for (int i = 0; i < left.size(); i++)
    {
        low = lower_bound(right.begin(), right.end(), a - left[i]) - right.begin();
        high = upper_bound(right.begin(), right.end(), b - left[i]) - right.begin();
        ans += (high - low);
    }

    cout << ans;

    return 0;
}