/*Isomorphic Strings -> Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’ */

#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256 // there are 256 characters in the ascii table

bool areIsomorphic(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    bool present[256] = {false};
    int map[256];
    memset(map, -1, sizeof(map));

    for (int i = 0; i < s1.length(); i++)
    {
        // here mapping of ascii values
        if (map[s1[i]] == -1) // first occurence
        {
            if (present[s2[i]])
            {
                return false;
            }
            present[s2[i]] = true;
            map[s1[i]] = s2[i];
        }
        else
        {
            if (map[s1[i]] != s2[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << areIsomorphic(s1, s2);

    return 0;
}