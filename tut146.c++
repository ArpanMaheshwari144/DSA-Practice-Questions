/*Copy set bits in a range -> Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also.

Examples :
Input  : x = 10, y = 13, l = 2, r = 3
Output : x = 14
Explanation -> Binary representation of 10 is 1010 and 
that of y is 1101. There is one set bit
in y at 3’rd position (in given range). 
After we copy this bit to x, x becomes 1110
which is binary representation of 14.

Input  : x = 8, y = 7, l = 1, r = 2
Output : x = 11
*/

// if we want to check if a bit is set(1) or not then we use &(bitwise and) operator
// if we want to set a bit is set(1) then we use |(bitwise or) operator

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, l, r;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    cout << "Enter the range: ";
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        if (y & (1 << (i - 1))) // checking the set bit
        {
            x = x | (1 << (i - 1)); // setting the set bit
        }
    }

    cout << "The number is: " << x;

    return 0;
}