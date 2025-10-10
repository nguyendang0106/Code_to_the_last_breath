/*
Problem Statement

In AtCoder Kingdom, there are NN horse races being held.
Horses aged Ai  or younger can participate in the i-th race.
Among the N races, how many races can a K-year-old horse participate in?

Constraints

All input values are integers.

1≤N≤100

1≤Ai≤100

1≤K≤100



Input

The input is given from Standard Input in the following format:

N
A1  A2  …… AN
K


Output

Output the answer as an integer.



Sample Input 1


5
3 1 4 1 5
4


Sample Output 1


2


Horses aged 3 or younger can participate in the 1st race.

Horses aged 1 or younger can participate in the 2nd race.

Horses aged 4 or younger can participate in the 3rd race.

Horses aged 1 or younger can participate in the 4th race.

Horses aged 5 or younger can participate in the 5th race.

Among the 5 races, a 44-year-old horse can participate in the 3rd and 5th races, which is 2 races.


*/
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A;
int K;

void input()
{
    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cin >> K;
}

void solve()
{
    int res = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] >= K)
            res++;
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solve();

    return 0;
}

// duyệt đơn giản
// 22/06/2025