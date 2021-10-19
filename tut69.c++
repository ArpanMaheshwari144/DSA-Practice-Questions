/*Function to find Number of customers who could not get a computer -> Write a function “runCustomerSimulation” that takes following two inputs
a) An integer ‘n’: total number of computers in a cafe and a string:
b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.
A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.
For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.
runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0
runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int occupied = 0;
    int visited[26] = {0};
    int didNotGet = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (visited[s[i] - 'A'] == 0 && occupied < n)
        {
            visited[s[i] - 'A'] = 1;
            occupied++;
        }
        else if (visited[s[i] - 'A'] == 1 && occupied <= n)
        {
            occupied--;
            visited[s[i] - 'A'] = 0;
        }
        else
        {
            didNotGet++;
        }
    }

    cout << didNotGet / 2;
    return 0;
}