/* Find shortest safe route in a path with landmines -> Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.

Examples:  

Input: 
A 12 x 10 matrix with landmines marked as 0

[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]
[ 1  1  1  1  0  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]  
[ 1  1  1  1  1  0  1  1  1  1 ]
[ 1  0  1  1  1  1  1  1  0  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 0  1  1  1  1  0  1  1  1  1 ]
[ 1  1  1  1  1  1  1  1  1  1 ]
[ 1  1  1  0  1  1  1  1  1  1 ]

Output:  
Length of shortest safe route is 13
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int row, int col, set<pair<int, int>> &st, vector<vector<bool>> visited, int i, int j, int count)
{
    if (i == row || i < 0 || j < 0 || j == col || st.count({i, j}) || visited[i][j])
    {
        return INT_MAX;
    }

    if (j == col - 1)
    {
        return count;
    }

    visited[i][j] = true;
    int l1 = solve(row, col, st, visited, i + 1, j, count + 1); // down
    int l2 = solve(row, col, st, visited, i - 1, j, count + 1); // up
    int l3 = solve(row, col, st, visited, i, j + 1, count + 1); // right
    int l4 = solve(row, col, st, visited, i, j - 1, count + 1); // left
    visited[i][j] = false;

    return min({l1, l2, l3, l4});
}

int main()
{
    int row, col;
    cout << "Enter row and col: ";
    cin >> row >> col;
    vector<vector<int>> mat(row, vector<int>(col));
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }

    // we can not use unordered_set with pairs
    set<pair<int, int>> st;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                pair<int, int> p(i, j);
                st.insert(p);

                // checking the four adjacents
                if (i + 1 < row)
                {
                    pair<int, int> p(i + 1, j);
                    st.insert(p);
                }

                if (i - 1 >= 0)
                {
                    pair<int, int> p(i - 1, j);
                    st.insert(p);
                }

                if (j + 1 < col)
                {
                    pair<int, int> p(i, j + 1);
                    st.insert(p);
                }

                if (j - 1 >= 0)
                {
                    pair<int, int> p(i, j - 1);
                    st.insert(p);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        if (st.count({i, 0}) == 0)
        {
            int length = solve(row, col, st, visited, i, 0, 0);
            ans = min(ans, length);
        }
    }
    cout << ans;

    return 0;
}