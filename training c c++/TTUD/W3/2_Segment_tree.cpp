/*
Given a sequence of positive integers a1, a2, . . ., an. Perform a sequence of actions of following types:
update  i  v : assign ai = v
get-max  i  j : return the maximum value of the subsequence ai, ai+1, . . ., aj


Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
Line i + 3 (i = 1, 2, . . ., m): contains an action described above
Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10


Ouput
4
8
9
20
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
int m;
string query;
int ik, jk;

vector<int> res;
vector<int> max_st; // 2^0 + 2^1 + ... + 2^k = 2^(k - 1) - 1 < 4n (k = log(n))

int buildTree(int index, int L, int R)
{
    if (L == R)
    {
        return max_st[index] = arr[L];
    }

    int mid = (L + R) / 2;
    int max_left = buildTree(index * 2, L, mid);
    int max_right = buildTree(index * 2 + 1, mid + 1, R);

    return max_st[index] = max(max_left, max_right);
}

int getMax(int index, int L, int R, int a, int b)
{
    if (a > R || b < L) // [L, R] [a, b] or [a, b] [L, R]
    {
        return 0;
    }

    if (a <= L && R <= b) // [a [L, R] b]
    {
        return max_st[index];
    }

    int mid = (L + R) / 2;
    int max_left = getMax(index * 2, L, mid, a, b);
    int max_right = getMax(index * 2 + 1, mid + 1, R, a, b);

    return max(max_left, max_right);
}

void update(int index, int L, int R, int a, int b)
{
    if (a < L || a > R)
    {
        return;
    }

    if (L == R)
    {
        arr[L] = b;
        max_st[index] = b;
        return;
    }

    int mid = (L + R) / 2;
    update(index * 2, L, mid, a, b);
    update(index * 2 + 1, mid + 1, R, a, b);

    max_st[index] = max(max_st[index * 2], max_st[index * 2 + 1]);
}

void solve(string q, int a, int b)
{
    if (q == "get-max")
    {
        res.push_back(getMax(1, 1, n, a, b));
    }
    else if (q == "update")
    {
        update(1, 1, n, a, b);
    }
}

void input()
{
    cin >> n;
    arr.resize(n + 1);
    max_st.resize(4 * n);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int build_tree = buildTree(1, 1, n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> query;
        cin >> ik >> jk;

        solve(query, ik, jk);
    }
}

void output()
{
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
    {
        cout << (*it) << endl;
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