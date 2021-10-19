/* Longest Possible Route in a Matrix with Hurdles -> Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of the longest possible route possible from source to a destination within the matrix. We are allowed to move to only adjacent cells which are not hurdles. The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again. 0 represents hurdle and 1 represents a path 

Examples : 
Input : find longest path with source (0, 0) and destination (1, 7) 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } ,
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } 
         
Output : 24

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int r, int c, vector<vector<int>> mat, vector<vector<bool>> visited, int &ans, int pathRow, int pathCol, int destRow, int destCol, int pathLength)
{
    if (pathRow == destRow && pathCol == destCol)
    {
        if (ans < pathLength)
        {
            ans = pathLength;
        }
        return;
    }

    if (pathRow < 0 || pathCol < 0 || pathRow >= r || pathCol >= c || visited[pathRow][pathCol] || mat[pathRow][pathCol] == 0)
    {
        return;
    }

    visited[pathRow][pathCol] = true;
    solve(r, c, mat, visited, ans, pathRow, pathCol + 1, destRow, destCol, pathLength + 1); // for right
    solve(r, c, mat, visited, ans, pathRow, pathCol - 1, destRow, destCol, pathLength + 1); // for up
    solve(r, c, mat, visited, ans, pathRow - 1, pathCol, destRow, destCol, pathLength + 1); // for left
    solve(r, c, mat, visited, ans, pathRow + 1, pathCol, destRow, destCol, pathLength + 1); // for down
    visited[pathRow][pathCol] = false;                                                      // backtrack
    return;
}

int main()
{
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int x1, x2, y1, y2;

    vector<vector<int>> mat(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Enter source: ";
    cin >> x1 >> y1;

    cout << "Enter destination: ";
    cin >> x2 >> y2;

    vector<vector<bool>> visited(r, vector<bool>(c, false));

    int ans = INT_MIN;
    if (mat[x1][y1] == 0)
    {
        cout << "Source itself a hurdle";
    }
    else
    {
        solve(r, c, mat, visited, ans, x1, y1, x2, y2, 0);
        cout << "Maximum distance from source"
             << "(" << x1 << "," << y1 << ")"
             << " to destination"
             << "(" << x2 << "," << y2 << ")"
             << " is: " << ans;
    }
    return 0;
}