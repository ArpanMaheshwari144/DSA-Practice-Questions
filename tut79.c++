/*Product array puzzle -> Given an array A[] of size N, construct a Product Array P (of same size N) such that P[i] is equal to the product of all the elements of A except A[i].*/
#include <bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &v, int n)
{
    if (n == 1)
    {
        return {1};
    }

    vector<long long int> ans(n), pre(n, 1), suf(n, 1);

    long long int i;
    pre[0] = v[0];
    suf[n - 1] = v[n - 1];

    for (i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * v[i];
    }
    for (i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] * v[i];
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans[i] = suf[i + 1];
        }
        else if (i == n - 1)
        {
            ans[i] = pre[i - 1];
        }
        else
        {
            ans[i] = pre[i - 1] * suf[i + 1];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n), vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vec = productExceptSelf(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}