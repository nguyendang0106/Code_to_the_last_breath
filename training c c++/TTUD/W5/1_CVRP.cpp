/*
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity
Goal
Find a solution having minimal total travel distance
Note that:
There might be the case that a truck does not visit any client (empty route)
The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
Input
Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
Line 2: d[1],...,d[n](1≤d[i]≤10)
Line i+3 (i=0,…,n): the i th row of the distance matrix c (1≤c[i,j]≤30)
Output
Minimal total travel distance
Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int N, K, Q;
vector<int> demand;
vector<vector<int>> matrix;

int f_best = 1e9, f_cur = 0;
vector<int> load; // vector lưu tải trọng hiện tại cho từng xe
vector<int> visited;
vector<int> X; // X[1] = 3 -> điểm đi tiếp theo sau khi đến điểm 1 là điểm 3 [1, ..., k]
vector<int> Y; // Y[1] = u -> điểm xuất phát đầu tiên của xe 1 là u. Nếu Y[1] = 0 -> xe 1 ko được dùng       [1, ..., k]

int C_min = 1e9;
int segments; // số cạnh đã duyệt qua (tối đa n + k cạnh)
int nbR = 0;  // số xe đang được sử dụng

void input()
{
    cin >> N >> K >> Q;
    demand.resize(N + 1);
    matrix.resize(N + 1, vector<int>(N + 1));

    forn(i, N)
    {
        cin >> demand[i + 1];
    }

    forn(i, N + 1)
    {
        forn(j, N + 1)
        {
            cin >> matrix[i][j];
            if (i != j)
                C_min = min(C_min, matrix[i][j]);
        }
    }
}

void update_best(int v)
{
    if (f_cur + matrix[v][0] < f_best)
        f_best = f_cur + matrix[v][0];
}

bool check_X(int v, int k)
{
    // v = 0 luôn ok vì luôn có thể quay về depot
    if (v > 0)
    {
        if (visited[v] || load[k] - demand[v] < 0)
            return false;
    }

    return true;
}

// xây dựng lộ trình cho tất cả các xe
// gán thử cho X[s] ở xe k (gán điểm tiếp theo của s)
void TRY_X(int s, int k)
{
    // trong trường hợp điểm xuất phát đầu tiên của xe là 0 thì ta kiểm tra nên duyệt sang xe tiếp theo hay return
    if (s == 0)
    {
        if (k < K)
            TRY_X(Y[k + 1], k + 1);

        return;
    }

    forn(v, N + 1)
    {
        if (check_X(v, k))
        {
            X[s] = v;
            visited[v] = 1;
            load[k] -= demand[s];
            segments++;
            f_cur += matrix[s][v];

            // kiểm tra xem xe k đã về depot hay chưa?
            if (v > 0) // chưa về depot
            {
                // cắt nhánh
            }
            else // đã về depot
            {
                // xem đây có phải xe cuối không? = xem đã xây đủ k tuyến chưa?
                if (k == K)
                {
                }
                else
                {
                }
            }

            // back track
            visited[v] = 0;
            load[k] += demand[s];
            segments--;
            f_cur -= matrix[s][v];
        }
    }
}

bool check_Y(int v, int k)
{
}

// gán điểm xuất phát đầu tiên cho tất cả các xe
// gán thử cho Y[k]
void TRY_Y(int k)
{
}

void output()
{
    load.resize(N + 1, Q); // [1, ..., N]
    visited.resize(N + 1);
    X.resize(N + 1);
    Y.resize(N + 1);
    cout << f_best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();
}
