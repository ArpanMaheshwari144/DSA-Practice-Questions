/*Program to generate all possible valid IP addresses from given string -> Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A, B, C and D are numbers from 0 – 255. The numbers cannot be 0 prefixed unless they are 0.*/
#include <iostream>
#include <vector>
using namespace std;

// Function to get all the valid ip-addresses
void GetAllValidIpAddress(vector<string> &result, string givenString, int index, int count, string ipAddress)
{

    // If index greater than givenString size and we have four block
    if (givenString.size() == index && count == 4)
    {
        // Remove the last dot
        ipAddress.pop_back();

        // Add ip-address to the results
        result.push_back(ipAddress);
        return;
    }

    // To add one index to ip-address
    if (givenString.size() < index + 1)
        return;

    // Select one digit and call the same function for other blocks
    ipAddress = ipAddress + givenString.substr(index, 1) + '.';
    GetAllValidIpAddress(result, givenString, index + 1, count + 1, ipAddress);

    // Backtrack to generate another poosible ip address So we remove two index (one for the digit and other for the dot) from the end
    ipAddress.erase(ipAddress.end() - 2, ipAddress.end());

    // Select two consecutive digits and call the same function for other blocks
    if (givenString.size() < index + 2 || givenString[index] == '0')
        return;
    ipAddress = ipAddress + givenString.substr(index, 2) + '.';
    GetAllValidIpAddress(result, givenString, index + 2, count + 1, ipAddress);

    // Backtrack to generate another poosible ip address So we remove three index from the end
    ipAddress.erase(ipAddress.end() - 3, ipAddress.end());

    // Select three consecutive digits and call the same function for other blocks
    if (givenString.size() < index + 3 || stoi(givenString.substr(index, 3)) > 255)
        return;
    ipAddress += givenString.substr(index, 3) + '.';
    GetAllValidIpAddress(result, givenString, index + 3, count + 1, ipAddress);

    // Backtrack to generate another poosible ip address So we remove four index from the end
    ipAddress.erase(ipAddress.end() - 4, ipAddress.end());
}

int main()
{
    string givenString = "25525511135";

    // Fill result vector with all valid ip-addresses
    vector<string> result;
    GetAllValidIpAddress(result, givenString, 0, 0, "");

    // Print all the generated ip-addresses
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
    return 0;
}
