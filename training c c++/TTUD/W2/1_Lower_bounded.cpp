/*
Mô tả
The revenue of a shop on day i is a[i] (i = 1, 2, . . ., n).  Given a threshold D (positive integer), compute the nunmber Q of consecutive days in which the total revenue is geater or equal to D.
Input
Line 1: contains 2 positive integers n and D (1 <= n <= 1000, 1 <= D <= 1000)
Line 2: contains n integers a[1], a[2], . . ., a[n] (1 <= a[i] <= 100)

Output
Write the value Q

Example
Input
5 12
1 6 4 2 9

Output
5

Explanation: there are 5 sequence of consecutive days satisfying the constraint:
1 6 4 2
1 6 4 2 9
6 4 2
6 4 2 9
4 2 9

*/

#include <iostream>
#include <vector>

using namespace std;

int n, D;
vector<int> ve;

int res;
vector<int> prefix_sum_ve;

void input()
{
    cin >> n >> D;
    ve.resize(n);

    int h = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ve[i];
        h += ve[i];
        prefix_sum_ve.push_back(h);
    }
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (prefix_sum_ve[j] - prefix_sum_ve[i] + ve[i] >= D)
                res++;
        }
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}