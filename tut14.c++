/* Common elements -> Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> v;
    set<int> s;
    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            s.insert(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] <= b[j] && a[i] <= c[k])
        {
            i++;
        }
        else if (b[j] <= a[i] && b[j] <= c[k])
        {
            j++;
        }
        else if (c[k] <= a[i] && c[k] <= b[j])
        {
            k++;
        }
    }
    v.assign(s.begin(), s.end());
    return v;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int a[n1], b[n2], c[n3];

    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> c[i];
    }

    vector<int> ans = commonElements(a, b, c, n1, n2, n3);

    if (ans.size() == 0)
    {
        cout << -1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
