// Spirally traversing a matrix -> Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int mat[n][m], i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int k, l;
    k = 0;
    l = 0;
    while (k < n && l < m)
    {
        for (i = l; i < m; i++)
        {
            cout << mat[k][i] << " ";
        }
        k++;

        for (i = k; i < n; i++)
        {
            cout << mat[i][m - 1] << " ";
        }
        m--;

        if (k < n)
        {
            for (i = m - 1; i >= 1; i--)
            {
                cout << mat[n - 1][i] << " ";
            }
            m--;
        }

        if (l < m)
        {
            for (i = n - 1; i >= k; i--)
            {
                cout << mat[i][l] << " ";
            }
            l++;
        }
    }

    return 0;
}