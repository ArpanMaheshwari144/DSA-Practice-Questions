/*Largest area rectangular sub-matrix with equal number of 1’s and 0’s -> Given a binary matrix. The problem is to find the largest area rectangular sub-matrix with equal number of 1’s and 0’s.

Examples:
Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 1} }
Output : 8 sq. units
        (Top, left): (0, 0)
        (Bottom, right): (3, 1)

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 1} }            
Output : 6 sq. units
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> subSum(vector<int> arr, int n)
{
    unordered_map<int, int> mp;
    int maxlen = 0;
    int sum = 0;
    int ending_index = -1;

    // Pick a starting point
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0)
        {
            maxlen = max(maxlen, 1);
        }

        if (sum == 0)
        {
            maxlen = max(maxlen, i + 1);
            ending_index = i;
        }

        if (mp.find(sum) != mp.end())
        {
            if (maxlen < i - (int)mp[sum])
            {
                maxlen = i - mp[sum];
                ending_index = i;
            }
        }
        else
        {
            mp[sum] = i;
        }
    }
    pair<int, int> p(maxlen, ending_index);
    return p;
}

int main()
{
    int r, c;

    // declaraing these variables for printing the matrix
    int starting_row = 0;
    int ending_row = 0;
    int starting_col = 0;
    int ending_col = 0;

    cin >> r >> c;

    // 2-D Matrix
    vector<vector<int>> mat(r, vector<int>(c)), temp_mat(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                temp_mat[i][j] = 1;
            }
            else
            {
                temp_mat[i][j] = -1;
            }
        }
    }

    int final_length = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        vector<int> current_array(c);
        for (int j = i; j < r; j++)
        {
            for (int col = 0; col < c; col++)
            {
                current_array[col] += temp_mat[j][col];
            }
            pair<int, int> p = subSum(current_array, c);

            if (final_length * (ending_row - starting_row + 1) < (p.first * (j - i + 1)))
            {
                final_length = p.first;
                starting_row = i;
                ending_row = j;
                starting_col = p.second - p.first + 1; // p.first = maxlen
                ending_col = p.second;                 // p.second = ending_index
            }
        }
    }

    int final_area = final_length * (ending_row - starting_row + 1);
    cout << "Area is: " << final_area << endl;

    cout << "Indexes are: ";
    cout << starting_row << " " << ending_row << " " << starting_col << " " << ending_col << endl;

    cout << "Answer matrix is ==> " << endl;
    for (int i = starting_row; i <= ending_row; i++)
    {
        for (int j = starting_col; j <= ending_col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}