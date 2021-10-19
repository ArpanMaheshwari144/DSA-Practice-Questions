// Permutations of a given string -> Given a string S. The task is to print all permutations of a given string.
#include <bits/stdc++.h>
using namespace std;

void permutation(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << " ";
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permutation(s, l + 1, r); // recursion
            swap(s[l], s[i]);         // backtracking
        }
    }
}

int main()
{
    string s;
    cin >> s;
    permutation(s, 0, s.length() - 1);

    return 0;
}