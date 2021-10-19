/* Row with max 1s -> Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.*/
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int max_row_element = 0;
    int j = m - 1;
    int i = 0;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == 1)
        {
            max_row_element = i;
            j--;
        }
        else
        {
            i++;
        }
    }
    return max_row_element;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Row " << rowWithMax1s(arr, n, m) << " contains maximum number of 1's";

    return 0;
}