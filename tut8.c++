// Find largest sum contigous subarray(kadane's algo)
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long int currentSum = a[0], maxSum = a[0];

    for (i = 1; i < n; i++)
    {
        currentSum = max(currentSum + a[i], a[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum;

    return 0;
}