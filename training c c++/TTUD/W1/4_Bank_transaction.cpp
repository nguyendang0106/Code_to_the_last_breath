/*
Mô tả
The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
                                                                    <from_account>   <to_account>   <money>   <time_point>   <atm>
In which:
•	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
•	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
•	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
•	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
•	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds)
A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
Write a program that process the following queries:
?number_transactions: compute the total number of transactions of the data
?total_money_transaction: compute the total amount of money of transactions
?list_sorted_accounts: compute the sequence of bank accounts (including sending and receiving accounts) appearing in the transaction (sorted in an increasing (alphabetical) order)
?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>
?inspect_cycle <account> k : return 1 if there is a transaction cycle of length k, starting from <account>, and return 0, otherwise
Input (stdin)
The input consists of 2 blocks of information: the data block and the query block
•	The data block consists of lines:
o	Each line contains the information about a transaction described above
o	The data is terminated by a line containing #
•	The query block consists of lines:
o	Each line is a query described above
o	The query block is terminated by a line containing #

Output (stdout)
•	Print to stdout (in each line) the result of each query described above

Example
Input
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?number_transactions
?total_money_transaction
?list_sorted_accounts
?total_money_transaction_from T000010010
?inspect_cycle T000010010 3
#
Output
9
19500
T000010010 T000010020 T000010030 T000010040
4500
1
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int num_trans = 0;
int total_money = 0;
vector<string> acc_from;
// vector<string> acc_to;
map<string, int> acc_money;
unordered_map<string, vector<string>> adj;
unordered_map<string, int> visited;

string acc1, acc2, time_point, atm, query;
int money, cycle_length;

map<int, string> res;

bool check_cycle(string start, string node, int k, int depth, unordered_map<string, int> &visited)
{
    if (depth == k)
    {
        if (node == start)
            return true;
        else
            return false;
    }

    for (string v : adj[node])
    {
        if (visited[v])
            continue;

        visited[v] = 1;

        if (check_cycle(start, v, k, depth + 1, visited))
        {
            return true;
        }

        visited[v] = 0;
    }

    return false;
}

void input()
{
    while (1)
    {
        cin >> acc1;

        if (acc1 == "#")
        {
            break;
        }
        else
        {
            cin >> acc2 >> money >> time_point >> atm;

            if (acc1 != acc2)
            {
                adj[acc1].push_back(acc2);
            }

            num_trans++;
            total_money += money;

            acc_from.push_back(acc1);
            // acc_to.push_back(acc2);

            acc_money[acc1] += money;
            acc_money[acc2] += 0;
        }
    }

    int cnt = 0;
    while (1)
    {
        cin >> query;

        if (query == "#")
        {
            break;
        }
        else if (query == "?number_transactions")
        {
            res[cnt] = to_string(num_trans);
        }
        else if (query == "?total_money_transaction")
        {
            res[cnt] = to_string(total_money);
        }
        else if (query == "?list_sorted_accounts")
        {
            for (map<string, int>::iterator it = acc_money.begin(); it != acc_money.end(); it++)
            {
                res[cnt] += it->first + " ";
            }
        }
        else if (query == "?total_money_transaction_from")
        {
            cin >> acc1;
            res[cnt] = to_string(acc_money[acc1]);
        }
        else if (query == "?inspect_cycle")
        {
            cin >> acc1 >> cycle_length;

            visited.clear();

            if (check_cycle(acc1, acc1, cycle_length, 0, visited))
            {
                res[cnt] = to_string(1);
            }
            else
            {
                res[cnt] = to_string(0);
            }
        }

        cnt++;
    }
}

void output()
{
    for (map<int, string>::iterator it = res.begin(); it != res.end(); it++)
    {
        cout << it->second << endl; // (*it).second
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}