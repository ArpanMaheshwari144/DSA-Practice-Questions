// Print all the duplicates in the input string
#include <iostream>
using namespace std;
#define NO_OF_CHARS 256

void printDuplicates(string s)
{
    int count[NO_OF_CHARS] = {};
    for (int i = 0; i < s.size(); i++)
        count[s[i]]++; //increment the count of each character by using ASCII of character as key
    for (int i = 0; i < s.size(); i++)
        if (count[s[i]] > 1) //
        {
            cout << s[i] << "   count = " << count[s[i]] << endl;
            count[s[i]] = 0;
        }
}
int main()
{
    string s = "Arpan Maheshwari";
    cout << "Input string is " << s << endl;
    printDuplicates(s);
}