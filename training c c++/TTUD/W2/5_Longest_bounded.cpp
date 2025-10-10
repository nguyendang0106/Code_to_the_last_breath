/*
Mô tả
Given a sequence of positive integers a = a1, a2, . . ., an. A subsequence of a is defined to be a sequence of consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n). The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.
Input
Line 1: contains two positive integers n and Q (1 <= n <= 10^6, 1 <= Q <= 100000)
Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000).
Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4
Output
5
*/

#include <iostream>
#include <vector>

using namespace std;

int n, Q;
vector<int> a;

int res = 0;

void input()
{
    cin >> n >> Q;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void output()
{
    int L = 0, R = 0, S = 0;

    for (int R = 0; R < n; R++)
    {
        S += a[R];

        while (S > Q)
        {
            S -= a[L];
            L++;
        }

        res = max(res, R - L + 1);
    }

    cout << ((res != 0) ? res : -1);
}
int main()
{
    input();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    output();

    return 0;
}
