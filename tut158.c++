/*Gold Mine Problem -> Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right,right up or right down) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

Examples: 
Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: mat[][] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR (2,0) -> (3,1) -> (2,2) -> (2,3)

Input : mat[][] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
Output : 83
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row = 3, column = 3;
    int mat[row][column] = {{1, 3, 3},
                            {2, 1, 4},
                            {0, 6, 4}};

    for (int j = 1; j < column; j++)
    {
        for (int i = 0; i < row; i++)
        {
            // all 3 paths possible
            if (i > 0 && i < row - 1)
            {
                mat[i][j] += max({mat[i][j - 1], mat[i - 1][j - 1], mat[i + 1][j - 1]});
            }

            // right down not possible
            else if (i == 0 && i < row - 1)
            {
                mat[i][j] += max(mat[i][j - 1], mat[i + 1][j - 1]);
            }

            // right up not possible
            else
            {
                mat[i][j] += max(mat[i][j - 1], mat[i - 1][j - 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        ans = max(mat[i][column - 1], ans);
    }
    cout << ans;

    return 0;
}