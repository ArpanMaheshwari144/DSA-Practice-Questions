/*Largest rectangular sub-matrix whose sum is 0 -> Given a 2D matrix, find the largest rectangular sub-matrix whose sum is 0. for example consider the following N x M input matrix 
 
Examples: 
Input : 1,   2,   3
       -3,  -2,  -1          
        1,   7,   5

Output : 1,  2,  3          
        -3, -2, -1

Input :  9,  7, 16,  5
         1, -6, -7,  3          
         1,  8,  7,  9          
         7, -2,  0, 10

Output : -6,  -7
          8,   7          
         -2,   0    
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
    vector<vector<int>> mat(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
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
                current_array[col] += mat[j][col];
            }
            pair<int, int> p = subSum(current_array, c);

            // old area < new area and area = length * breadth
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