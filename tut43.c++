// Check if a string is a valid shuffle of two strings or not
#include <bits/stdc++.h>
using namespace std;

bool shuffleCheck(string first, string second, string result)
{
    // check length of result is same as sum of result of first and second
    if (first.length() + second.length() != result.length())
    {
        return false;
    }
    // variables to track each character of 3 strings
    int i = 0, j = 0, k = 0;

    // iterate through all characters of result
    while (k != result.length())
    {
        // check if first character of result matches with first character of first string
        if (i < first.length() && first.at(i) == result.at(k))
            i++;

        // check if first character of result matches the first character of second string
        else if (j < second.length() && second.at(j) == result.at(k))
            j++;

        // if the character doesn't match
        else
        {
            return false;
        }

        // access next character of result
        k++;
    }

    // after accessing all characters of result if either first or second has some characters left
    if (i < first.length() || j < second.length())
    {
        return false;
    }

    return true;
}

int main()
{
    string first = "XY";
    string second = "12";
    string results[] = {"1XY2", "Y12X"};

    // call the method to check if result string is shuffle of the string first and second
    for (string result : results)
    {
        if (shuffleCheck(first, second, result) == true)
        {
            cout << result << " is a valid shuffle of " << first << " and " << second << endl;
        }
        else
        {
            cout << result << " is not a valid shuffle of " << first << " and " << second;
        }
    }
    return 0;
}
