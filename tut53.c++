/*Convert a sentence into its equivalent mobile numeric keypad sequence -> Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence.*/

#include <bits/stdc++.h>
using namespace std;

string printSequence(string arr[], string input)
{
    string output = "";

    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";

        else
        {
            // Calculating index for each character
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }
    // Output sequence
    return output;
}

int main()
{
    // storing the sequence in array
    string str[] = {"2", "22", "222",          // "A", "B", "C"
                    "3", "33", "333",          // "D", "E", "F"
                    "4", "44", "444",          // "G", "H", "I"
                    "5", "55", "555",          // "J", "K", "L"
                    "6", "66", "666",          // "M", "N", "O"
                    "7", "77", "777", "7777",  // "P", "Q", "R", "S"
                    "8", "88", "888",          // "T", "U", "V"
                    "9", "99", "999", "9999"}; // "W", "X", "Y", "Z"

    string input = "ARPAN";
    cout << printSequence(str, input);
    return 0;
}
