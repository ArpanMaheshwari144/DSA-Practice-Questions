/*DEFKIN - Defense of a Kingdom -> Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle.
Help Theodore write a program that calculates the penalty of the given position.

Input
The first line of the input file contains the number of test cases.
Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

Example
Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int w, h, n, i;
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;
    cout << "Enter number of towers: ";
    cin >> n;

    vector<long long int> x, y;
    long long int maxLength = 0, maxWidth = 0;
    for (i = 0; i < n; i++)
    {
        long long int a, b;
        cout << "Enter the co-ordinates: ";
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    x.push_back(w + 1); // includes last row
    y.push_back(h + 1); // includes last column
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    maxLength = x[0] - 1; // length represents on x-axis
    maxWidth = y[0] - 1;  // length represents on y-axis

    for (i = 1; i <= n; i++)
    {
        if (maxLength < (x[i] - x[i - 1] - 1))
        {
            maxLength = x[i] - x[i - 1] - 1;
        }
        if (maxWidth < (y[i] - y[i - 1] - 1))
        {
            maxWidth = y[i] - y[i - 1] - 1;
        }
    }

    cout << maxLength * maxWidth;

    return 0;
}