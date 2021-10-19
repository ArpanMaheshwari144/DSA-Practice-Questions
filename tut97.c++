/*ANARC05B - The Double HeLiX -> Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
printed in bold:
First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can "walk" over these two sequences in the following way:
You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62
Input:
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format: n v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.
Output:
For each test case, write on a separate line, the largest possible sum that can be produced.
Sample
Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

Output:
450
2100
*/
#include <bits/stdc++.h>
using namespace std;

int maxSumPath(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;

    int max_sum = 0;

    int sum1 = 0;
    int sum2 = 0;

    // two pointers algo
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            sum1 += arr1[i];
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            sum2 += arr2[j];
            j++;
        }
        else
        {
            // intersection point
            max_sum = max(sum1, sum2) + max_sum;
            max_sum = max_sum + arr1[i]; // or max_sum = max_sum + arr2[j]
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }

    while (i < m)
    {
        sum1 = sum1 + arr1[i];
        i++;
    }

    while (j < n)
    {
        sum2 = sum2 + arr2[j];
        j++;
    }

    max_sum = max_sum + max(sum1, sum2);
    return max_sum;
}

int main()
{
    int n1, n2, i;
    cin >> n1;

    int a[n1];
    for (i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cin >> n2;
    int b[n2];
    for (i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    cout << maxSumPath(a, b, n1, n2);

    return 0;
}