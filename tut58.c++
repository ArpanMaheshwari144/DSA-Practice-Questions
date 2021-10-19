/*Min Number of Flips -> Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i, f = 0;
    int c1 = 0, c2 = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (f == 0)
        {
            if (s[i] == '1')
            {
                c1++;
            }
        }
        else
        {
            if (s[i] == '0')
            {
                c1++;
            }
        }
        f = !f;
    }

    f = 1;
    for (i = 0; i < s.length(); i++)
    {
        if (f == 1)
        {
            if (s[i] == '0')
            {
                c2++;
            }
        }
        else
        {
            if (s[i] == '1')
            {
                c2++;
            }
        }
        f = !f;
    }

    cout << min(c1, c2);

    return 0;
}