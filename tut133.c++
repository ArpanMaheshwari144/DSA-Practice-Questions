/*Minimum sum of absolute difference of pairs of two arrays -> Given two arrays a[] and b[] of equal length n. The task is to pair each element of array a to an element in array b, such that sum S of absolute differences of all the pairs is minimum. Suppose, two elements a[i] and a[j] (i != j) of a are paired with elements b[p] and b[q] of b respectively, 
then p should not be equal to q.

Examples: 
Input :  a[] = {3, 2, 1}
         b[] = {2, 1, 3}
Output : 0
Explaination :
1st pairing: |3 - 2| + |2 - 1| + |1 - 3| = 1 + 1 + 2 = 4
2nd pairing: |3 - 2| + |1 - 1| + |2 - 3| = 1 + 0 + 1 = 2
3rd pairing: |2 - 2| + |3 - 1| + |1 - 3| = 0 + 2 + 2 = 4
4th pairing: |1 - 2| + |2 - 1| + |3 - 3| = 1 + 1 + 0 = 2
5th pairing: |2 - 2| + |1 - 1| + |3 - 3| = 0 + 0 + 0 = 0
6th pairing: |1 - 2| + |3 - 1| + |2 - 3| = 1 + 2 + 1 = 4
Therefore, 5th pairing has minimum sum of absolute difference.

Input :  n = 4
         a[] = {4, 1, 8, 7}
         b[] = {2, 3, 6, 5}
Output : 6
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a[] = {4, 1, 8, 7};
    long long int b[] = {2, 3, 6, 5};
    long long int n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n);
    sort(b, b + n);

    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + abs(a[i] - b[i]);
    }

    cout << sum;

    return 0;
}