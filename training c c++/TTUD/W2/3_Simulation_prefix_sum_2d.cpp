/*
Mô tả
Given a table of n rows (1, 2, ..., n) and m columns (1, 2, ..., m). Each cell (i,j) has a non-negative integer a(i,j).
Perform a sequence of queries (r1, c1, r2, c2) which returns the sum of elements of the sub-table from row r1 to row r2 and from column c1 to column c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m).

Input
Line 1: contains n and m (1 <= n, m <= 1000)
Line i+1(i = 1, 2, ..., n): contains the elements on row i of the table
Line n+2: contains a positive integer Q (1 <= Q <= 100000) which is the number of queries
Line q+n+2 (q = 1, 2, ..., Q): contains r1, c1, r2, c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m)

Output
Write in each line the result of the corresponding query read from the input

Example
Input
3 4
1 1 0 1
1 1 1 0
0 1 0 0
3
2 3 3 4
1 3 3 4
2 2 3 4

Output
1
2
3
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> table;
int Q;
int r1, c1, r2, c2;

vector<vector<unsigned long long>> pfs_table;
vector<unsigned long long> res;

void solve(int r_1, int c_1, int r_2, int c_2)
{
    res.push_back(pfs_table[r_2][c_2] - pfs_table[r_1 - 1][c_2] - pfs_table[r_2][c_1 - 1] + pfs_table[r_1 - 1][c_1 - 1]);
}

void input()
{
    cin >> n >> m;
    table.resize(n, vector<int>(m));
    pfs_table.resize(n + 1, vector<unsigned long long>(m + 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
            pfs_table[i + 1][j + 1] = pfs_table[i][j + 1] + pfs_table[i + 1][j] - pfs_table[i][j] + table[i][j];
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        solve(r1, c1, r2, c2);
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