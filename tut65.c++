/*Print Anagrams Together -> Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    // Your Code Here
    map<string, vector<string>> mp;
    for (auto x : string_list)
    {
        string k = x;
        sort(k.begin(), k.end());
        mp[k].push_back(x);
    }
    vector<vector<string>> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> string_list(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> string_list[i];
    }

    vector<vector<string>> result = Anagrams(string_list);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}