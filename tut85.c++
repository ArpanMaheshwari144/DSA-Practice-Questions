/*Bishu and Soldiers -> Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in previous round will reborn.Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and total sum of their powers.*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n; // size of an array (soldiers)
    cin >> n;
    vector<long long> v(n);

    for (int i = 0; i < n; i++)
    {

        cin >> v[i]; // poer of soldiers
    }

    sort(v.begin(), v.end());

    long long q; // rounds to fight
    cin >> q;

    while (q--)
    {
        long long a; // bishu's power
        cin >> a;
        long long start = -1, end = n;
        while (end > start + 1)
        {
            long long mid = start + (end - start) / 2;
            if (v[mid] > a)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        long long sum = 0; // total sum of their powers.
        for (int i = 0; i <= start; i++)
        {
            sum += v[i];
        }
        cout << start + 1 << " " << sum << endl;
    }
    return 0;
}