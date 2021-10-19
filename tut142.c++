/*CHOCOLA - Chocolate -> We are given a bar of chocolate composed of m*n square pieces. One should break the chocolate into single squares. Parts of the chocolate may be broken along the vertical and horizontal lines as indicated by the broken lines in the picture.
A single break of a part of the chocolate along a chosen vertical or horizontal line divides that part into two smaller ones. Each break of a part of the chocolate is charged a cost expressed by a positive integer. This cost does not depend on the size of the part that is being broken but only depends on the line the break goes along. Let us denote the costs of breaking along consecutive vertical lines with x1, x2, ..., xm-1 and along horizontal lines with y1, y2, ..., yn-1.
The cost of breaking the whole bar into single squares is the sum of the successive breaks. One should compute the minimal cost of breaking the whole chocolate into single squares.
Task:
Write a program that for each test case:
Reads the numbers x1, x2, ..., xm-1 and y1, y2, ..., yn-1
Computes the minimal cost of breaking the whole chocolate into single squares, writes the result.

Input:
One integer in the first line, stating the number of test cases, followed by a blank line. There will be not more than 20 tests.
For each test case, at the first line there are two positive integers m and n separated by a single space, 2 <= m,n <= 1000. In the successive m-1 lines there are numbers x1, x2, ..., xm-1, one per line, 1 <= xi <= 1000. In the successive n-1 lines there are numbers y1, y2, ..., yn-1, one per line, 1 <= yi <= 1000.
The test cases will be separated by a single blank line.

Output:
For each test case : write one integer - the minimal cost of breaking the whole chocolate into single squares.

Example
Input:
1

6 4
2
1
3
1
4
4
1
2

Output:
42

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int i, j, n, m, total, ans = 0;
    cout << "Enter the value of m and n: ";
    cin >> m >> n;

    long long int h[m - 1], v[n - 1];

    cout << "Enter the horizontal array: ";
    for (i = 0; i < m - 1; i++)
    {
        cin >> h[i];
    }

    cout << "Enter the vertical array: ";
    for (i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }

    sort(h, h + m - 1, greater<int>());
    sort(v, v + n - 1, greater<int>());

    i = 0, j = 0;
    long long int vertical = 1, horizontal = 1;
    while (i < m - 1 && j < n - 1)
    {
        // for cutting horizontally
        if (h[i] > v[j])
        {
            ans += h[i] * vertical;
            horizontal++; // horizontal pieces
            i++;
        }
        // for cutting vertically
        else
        {
            ans += v[j] * horizontal;
            vertical++; // vertical pieces
            j++;
        }
    }

    total = 0;
    while (i < m - 1)
    {
        total += h[i];
        i++;
    }
    ans += total * vertical;

    total = 0;
    while (j < n - 1)
    {
        total += v[j];
        j++;
    }
    ans += total * horizontal;

    cout << ans;

    return 0;
}