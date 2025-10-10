#include <iostream>
#include <vector>

using namespace std;

int t, n;

vector<int> out;

void solve(int num)
{
    out.push_back((num % 3 == 0) ? 0 : 3 - (num % 3));
}

void input()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        solve(n);
    }
}

void output()
{
    for (vector<int>::iterator it = out.begin(); it != out.end(); it++)
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