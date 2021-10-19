/* Given a N*N board with the Knight(Horse) placed on the first block of an empty board. Moving according to the rules of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.

Example:

Input : N = 4

Output:
0 9 12 9 
7 4 1 10
2 11 8 5
9 6 3 12
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n, int i, int j, int count, vector<vector<int>> &mat, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
    {
        return;
    }

    if (visited[i][j])
    {
        return;
    }

    // bcoz we start count from 0 and it will print upto 63
    if (count == (n * n - 1))
    {
        mat[i][j] = count;
        return;
    }

    visited[i][j] = true;
    mat[i][j] = count;

    // 8 possible moves for Knight
    solve(n, i - 2, j + 1, count + 1, mat, visited);
    solve(n, i - 2, j - 1, count + 1, mat, visited);
    solve(n, i + 2, j + 1, count + 1, mat, visited);
    solve(n, i + 2, j - 1, count + 1, mat, visited);
    solve(n, i - 1, j + 2, count + 1, mat, visited);
    solve(n, i - 1, j - 2, count + 1, mat, visited);
    solve(n, i + 1, j + 2, count + 1, mat, visited);
    solve(n, i + 1, j - 2, count + 1, mat, visited);

    // Backtrack
    visited[i][j] = false;

    return;
}

int main()
{
    int n;
    cout << "Enter the size of board: ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    solve(n, 0, 0, 0, mat, visited);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}