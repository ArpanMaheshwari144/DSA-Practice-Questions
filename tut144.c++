/*Calculate square of a number without using *, / and pow() -> Given an integer n, calculate the square of a number without using *, / and pow(). 

Examples : 
Input: n = 5
Output: 25

Input: 7
Output: 49

Input: n = 12
Output: 144
*/
#include <bits/stdc++.h>
using namespace std;

int square(int n)
{
    // Base case
    if (n == 0)
    {
        return 0;
    }

    // Handle negative number
    if (n < 0)
    {
        n = -n;
    }

    // Get floor(n/2) using right shift
    int x = n >> 1; // divide by 2

    // If n is odd
    if (n & 1)
    {
        /*       7
                /
               3 -> return 9
              /
             1 -> return 1
            /
           0 -> return 0
        -> 9 << 2 + 3 << 2 + 1 => 36 + 12 + 1 => 49     
        */

        // << 2 it means the number is mutiply by 4
        return ((square(x) << 2) + (x << 2) + 1);
    }
    else // If n is even
    {
        /*       8
                /
               4 -> return 16
              /
             2 -> return 4
            /
           1 -> return 1
          /
         0 -> return 0
        -> 16 << 2 => 64     
        */
        return (square(x) << 2);
    }
}

// Driver Code
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "The square of " << n << " is: " << square(n);
    return 0;
}
