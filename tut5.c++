// Move all the negative elements to one side of the array
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}