/*Program for nth Catalan Number -> Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

1. Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
2. Count the number of possible Binary Search Trees with n keys.
3. Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
4. Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.
 
The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  
 
Recursive Solution: Catalan numbers satisfy the following recursive formula.
                     n
C{0}=1 and C{n+1} =  Σ C{i} C{n-i} \ for n >= 0
                    i=0                     
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int catalan[n + 1];
    memset(catalan, 0, sizeof(catalan));
    catalan[0] = 1;
    catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    cout << "The " << n << " catalan number is: " << catalan[n];

    return 0;
}