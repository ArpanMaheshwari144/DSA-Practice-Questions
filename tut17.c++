// Find factorial of a large number

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void multiply(vector<int> &v, int x)
{
    int carry = 0, mul;

    for (int i = 0; i < v.size(); i++)
    {
        mul = v[i] * x + carry;
        v[i] = mul % 10;
        carry = mul / 10;
    }
    while (carry)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

void fact(int n)
{
    vector<int> v;
    v.push_back(1);

    for (int i = 1; i <= n; i++)
    {
        multiply(v, i);
    }

    reverse(v.begin(), v.end());
    int i = 0;

    while (v[i] == 0)
    {
        i++;
    }
    for (int j = i; j < v.size(); j++)
    {
        cout << v[j];
    }
}

int main()
{
    int n;
    cin >> n;

    fact(n);

    return 0;
}