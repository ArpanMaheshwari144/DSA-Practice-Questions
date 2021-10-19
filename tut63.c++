/*Rearrange characters -> Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int i, maxfreq = 0;
    int freq[26];
    memset(freq, 0, sizeof(freq));

    for (i = 0; i < s.length(); ++i)
    {
        freq[s[i] - 'a']++;
        maxfreq = max(maxfreq, freq[s[i] - 'a']);
    }

    if (2 * maxfreq <= s.length() + 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}