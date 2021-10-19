/*Longest Palindrome in a String -> Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).*/
#include <bits/stdc++.h>
using namespace std;

string palindrome(string s, int l, int r)
{
    if (s == "" || l > r)
    {
        return "";
    }
    while (l >= 0 && r < s.length() && s[l] == s[r])
    {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    string longest = s.substr(0, 1);
    for (int i = 0; i < n - 1; i++)
    {
        string p1 = palindrome(s, i, i);
        if (p1.length() > longest.length())
        {
            longest = p1;
        }
        string p2 = palindrome(s, i, i + 1);
        if (p2.length() > longest.length())
        {
            longest = p2;
        }
    }

    cout << longest;

    // OR

    // string s;
    // cin >> s;
    // vector<string> v;
    // string s1, s2;
    // int i, j, m = 0;
    // for (i = 0; i < s.length(); i++)
    // {
    //     s1.push_back(s[i]);
    //     v.push_back(s1);
    //     for (j = i + 1; j < s.length(); j++)
    //     {
    //         s1.push_back(s[j]);
    //         v.push_back(s1);
    //     }
    //     s1.clear();
    // }

    // for (i = 0; i < v.size(); i++)
    // {
    //     s1 = v[i];
    //     reverse(s1.begin(), s1.end());
    //     if (s1 == v[i])
    //     {
    //         if (m < s1.length())
    //         {
    //             m = s1.length();
    //             s2 = v[i];
    //         }
    //     }
    // }

    // cout << s2;

    return 0;
}