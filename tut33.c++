/*Median in a row-wise sorted Matrix -> Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.*/

#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &m, int r, int c)
{
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        mn = min(mn, m[i][0]);
        mx = max(mx, m[i][c - 1]);
    }

    int needed = (r * c + 1) / 2;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            count += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
        }
        if (count < needed)
        {
            mn = mid + 1;
        }
        else
        {
            mx = mid;
        }
    }
    return mn;
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << median(matrix, r, c);

    return 0;
}