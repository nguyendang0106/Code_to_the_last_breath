/*
Mô tả
Given a sequence of integers a1, a2, . . ., an. Perform a sequence of Q queries q(i,j) that returns the sum of ai, ai+1, . . ., aj.

Input
Line 1: contains a positive integer n (2 <= n <= 100000)
Line 2: contains a1, a2, ..., an. (1 <= ai <= 1000)
Line 3: contains a positive integer Q (1 <= Q <= 100000)
Line 3 + k (k = 1, 2, ..., Q): contains 2 positive integers i and j (1 <= i < j <= n) of the kth query

Output
Write in each line, the result of the corresponding query read from the input

Example
Input
5
5 8 7 1 9
4
1 2
1 5
1 3
4 5

Output
13
30
20
10
*/

#include <iostream>
#include <vector>

using namespace std;

int n, Q, start_pos, end_pos;
vector<int> a;

vector<unsigned long long> pfs_a;
vector<unsigned long long> res;

void solve(int s, int e)
{
    res.push_back(pfs_a[e - 1] - pfs_a[s - 1] + a[s - 1]);
}

void input()
{
    cin >> n;
    a.resize(n);

    unsigned long long h = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        h += a[i];
        pfs_a.push_back(h);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> start_pos >> end_pos;
        solve(start_pos, end_pos);
    }
}

void output()
{
    for (vector<unsigned long long>::iterator it = res.begin(); it != res.end(); it++)
    {
        cout << *it << endl;
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