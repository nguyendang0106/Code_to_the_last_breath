/*
Given a sequence of n integers a0,. . .,an-1. We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj. Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
Input
Line 1: n (1 <=  n <= 106)
Line 2: a0, . . . ,an-1 ( 1  <=  ai <= 106)
line 3: m (1  <= m <= 106)
Line k+3 (k=1, . . ., m): ik, jk (0  <=  ik < jk < n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> a;
int m;
int ik, jk;

int res;
vector<vector<int>> stb;

void buildSTB()
{
    stb.resize(log2(n) + 1, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        stb[0][i] = a[i];
    }

    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 0; j + (1 << i) - 1 < n; j++)
        {
            stb[i][j] = min(stb[i - 1][j], stb[i - 1][j + (1 << (i - 1))]);
        }
    }
}

void solve(int a, int b)
{
    int k = log2(b - a + 1);

    res += min(stb[k][a], stb[k][b - (1 << k) + 1]);
}

void input()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    buildSTB();

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> ik >> jk;
        solve(ik, jk);
    }
}

void output()
{
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