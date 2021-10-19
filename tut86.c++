/*Arithmetic Number -> Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference of an arithmetic sequence and an integer 'B'. you need to tell whether 'B' exists in the arithmetic sequence or not.*/

// Arithmetic Sequence Formula -> a + (n-1)d  -> a is first term, n is number of terms and d is common difference
// Now according to the question this formula can be reduce into -> A + (n-1)C = B

#include <bits/stdc++.h>
using namespace std;

int inSequence(int A, int B, int C)
{
    if (C == 0)
    {
        if (A == B)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (((B - A) / C) >= 0)
    {
        if (((B - A) % C) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << inSequence(A, B, C);
    return 0;
}