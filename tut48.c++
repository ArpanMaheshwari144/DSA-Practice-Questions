/*Split the binary string into substrings with equal number of 0s and 1s -> Given a binary string str of length N, the task is to find the maximum count of substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.*/
#include <bits/stdc++.h>
using namespace std;

int maxSubStr(string str, int n)
{
    // To store the count of 0s and 1s
    int count0 = 0, count1 = 0;

    // To store the count of maximum substrings str can be divided into
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
        if (count0 == count1)
        {
            cnt++;
        }
    }

    // It is not possible to split the string
    if (count0 != count1)
    {
        return -1;
    }

    return cnt;
}

int main()
{
    // string str = "0100110101";
    // string str = "0111100010";
    string str = "000111";
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}
