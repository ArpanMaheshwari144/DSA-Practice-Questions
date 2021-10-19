// Palindrome String -> Given a string S, check if it is palindrome or not.
#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s)
{
    int i, n = s.length();

    for (i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    string s;
    cin >> s;

    cout << isPalindrome(s);
    return 0;
}