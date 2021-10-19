/*Next Permutation -> mplement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers. If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
For example:
1,2,3 → 1,3,2
3,2,1 → 1,2,3*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    bool flag = false;
    int i;
    for (i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        int j;
        for (j = nums.size() - 1; j >= i; j--)
        {
            if (nums[j] > nums[i - 1])
            {
                swap(nums[j], nums[i - 1]);
                break;
            }
        }
    }
    else
    {
        i = 0;
    }
    sort(nums.begin() + i, nums.end());
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    nextPermutation(a);

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}