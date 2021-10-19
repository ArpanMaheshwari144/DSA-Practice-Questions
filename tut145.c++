/*Divide two integers without using multiplication, division and mod operator -> Given a two integers say a and b. Find the quotient after dividing a by b without using multiplication, division and mod operator.

Example: 
Input : a = 10, b = 3
Output : 3

Input : a = 43, b = -8
Output :  -5 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, i;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    int copy_a = a;
    int copy_b = b;

    int q = 0;
    while (a >= b)
    {
        // infinte loop
        for (i = 0;; i++)
        {
            if ((b * (1 << i)) > a)
            {
                break;
            }
        }
        a -= b * (1 << (i - 1));
        q += 1 << (i - 1);
    }
    cout << copy_a << "/" << copy_b << " = " << q;

    return 0;
}