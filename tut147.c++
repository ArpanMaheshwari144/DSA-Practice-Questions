/*Next Smaller Element -> Given an array, print the Next Smaller Element (NSE) for every element. The Smaller smaller Element for an element x is the first smaller element on the right side of x in array. Elements for which no smaller element exist (on right side), consider next smaller element as -1.

Examples: 
a) For any array, rightmost element always has next smaller element as -1. 
b) For an array which is sorted in increasing order, all elements have next smaller element as -1. 
c) For the input array [4, 8, 5, 2, 25}, the next smaller elements for each element are as follows.

Element       NSE
  4      -->   2
  8      -->   5
  5      -->   2
  2      -->   -1
  25     -->   -1
d) For the input array [13, 7, 6, 12}, the next smaller elements for each element are as follows.  

Element        NSE
  13     -->    7
  7      -->    6
  6      -->    -1
  12     -->    -1
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> nextSmallestElementToLeft(vector<long long> arr, int n)
{
    vector<long long int> v;
    stack<long long int> s;

    for (long long int i = n - 1; i >= 0; i--)
    {
        while (s.size() != 0)
        {
            if (s.top() > arr[i])
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());

    return v;
}

int main()
{
    vector<long long> arr = {13, 7, 6, 12};
    int n = arr.size();
    vector<long long> v = nextSmallestElementToLeft(arr, n);

    cout << "The array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nThe nearest smallest element to left for all the values in the array is: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " --> " << v[i] << endl;
    }

    return 0;
}