/*
Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example

Input
7 5
4
1 5
6 2
2 2
4 3
Output
1
*/

#include <iostream>
#include <vector>

using namespace std;

int H, W;
int n;
vector<int> hk;
vector<int> wk;

void input()
{
    cin >> H >> W;
    cin >> n;
    hk.resize(n);
    wk.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> hk[i] >> wk[i];
    }
}

bool check()
{
}

void solve()
{
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