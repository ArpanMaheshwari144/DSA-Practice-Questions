// A Program to check if strings are rotations of each other or not
#include <bits/stdc++.h>
using namespace std;

/* Function checks if passed strings (str1 and str2) are rotations of each other */
bool areRotations(string str1, string str2)
{
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;
    return (temp.find(str2) != string::npos); // string::npos -> static const size_t npos = -1;
}

int main()
{
    string str1 = "ABACD", str2 = "CDABA";
    if (areRotations(str1, str2))
        cout << "Strings are rotations of each other";
    else
        cout << "Strings are not rotations of each other";
    return 0;
}
