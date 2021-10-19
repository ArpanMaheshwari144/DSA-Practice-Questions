/* Find the K-th Permutation Sequence of first N natural numbers -> Given two integers N and K, find the Kth permutation sequence of numbers from 1 to N without using STL function.
Note: Assume that the inputs are such that Kth permutation of N number is always possible.

Examples: 
Input: N = 3, K = 4 
Output: 231 
Explanation: The ordered list of permutation sequence from integer 1 to 3 is : 123, 132, 213, 231, 312, 321. So, the 4th permutation sequence is “231”.

Input: N = 2, K = 1 
Output: 12 
Explanation: For n = 2, only 2 permutations are possible 12 21. So, the 1st permutation sequence is “12”. 
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n, int count, vector<int> ans, set<int> &s, vector<vector<int>> &v)
{
    if (count == 0)
    {
        v.push_back(ans);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        // we check whether the element is present in set or not
        if (s.count(i) == 0)
        {
            // recursion
            ans.push_back(i);
            s.insert(i);
            solve(n, count - 1, ans, s, v); 

            // backtrack
            ans.pop_back();
            s.erase(s.find(i));
        }
    }
    return;
}

int main()
{
    int n, k, count = 0;
    cin >> n >> k;
    count = n;
    set<int> s;
    vector<int> ans;
    vector<vector<int>> v;
    solve(n, count, ans, s, v);
    for (int i = 0; i < n; i++)
    {
        cout << v[k - 1][i];
    }

    return 0;
}