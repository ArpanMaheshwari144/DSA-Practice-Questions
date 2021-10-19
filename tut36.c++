// Rotate a matrix by 90 degree in clockwise direction without using any extra space
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int mat[n][m], i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "After rotate 90 degree in clockwise direction" << endl;

    for (j = 0; j < n; j++)
    {
        for (i = n - 1; i >= 0; i--)
        {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
