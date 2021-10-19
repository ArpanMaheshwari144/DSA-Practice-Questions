/* Print all possible paths from top left to bottom right of a mXn matrix -> The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples : 
Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4
*/

#include <bits/stdc++.h>
using namespace std;

void findPaths(int x, int y, int rows, int cols, vector<vector<int>> mat, vector<vector<bool>> &visited, vector<int> path, vector<vector<int>> &allPaths)
{
    if (x == rows - 1 && y == cols - 1)
    {
        path.push_back(mat[x][y]);
        allPaths.push_back(path);
        return;
    }

    if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y])
    {
        return;
    }

    path.push_back(mat[x][y]);
    visited[x][y] = true;

    // recursion
    findPaths(x, y + 1, rows, cols, mat, visited, path, allPaths); // for right
    findPaths(x + 1, y, rows, cols, mat, visited, path, allPaths); // for bottom

    // backtrack
    visited[x][y] = false;
    path.pop_back();
}

int main()
{
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> path;
    vector<vector<int>> allPaths;
    findPaths(0, 0, rows, cols, mat, visited, path, allPaths);
    cout << "New Resultant Matrix size: " << allPaths.size() << endl;
    cout << "New Resultant Matrix ==>" << endl;
    for (int i = 0; i < allPaths.size(); i++)
    {
        for (int j = 0; j < allPaths[i].size(); j++)
        {
            cout << allPaths[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}