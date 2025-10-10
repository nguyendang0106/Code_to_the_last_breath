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

using namespace std;

int n;
vector<int> a;
int m;
string query;
int ik, jk;

void getMax()
{
}

void update()
{
}

void solve(string q, int a, int b)
{
    if (q == "get-max")
    {
        getMax();
    }
    else if (q == "update")
    {
        update();
    }
}

void input()
{
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}