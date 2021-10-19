/*Minimum Swaps for Bracket Balancing ->  We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin >> n;
    string s;
    cin >> s;

    long int i, bracket = 0;
    long int count = 0;

    for (i = 0; i < n; i++)
    {
        if (s[i] == ']')
        {
            bracket--;
        }
        else if (bracket < 0)
        {
            count += abs(bracket);
            bracket++;
        }
        else
        {
            bracket++;
        }
    }
    cout << count;
    return 0;
}