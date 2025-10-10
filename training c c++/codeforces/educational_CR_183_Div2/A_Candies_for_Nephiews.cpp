/*
Monocarp has three nephews. New Year is coming, and Monocarp has 𝑛
 candies that he will gift to his nephews.

To ensure that none of the nephews feels left out, Monokarp wants to give each of the three nephews the same number of candies.

Determine the minimum number of candies that Monocarp needs to buy additionally so that he can give each of the three nephews the same number of candies. Note that all 𝑛
 candies that Monocarp initially has will be given to the nephews.

Input
The first line contains an integer 𝑡 (1≤𝑡≤100) — the number of test cases.

Each test case consists of one line containing one integer 𝑛 (1≤𝑛≤100) — the number of candies that Monocarp initially has.

Output
For each test case, print one integer — the minimum number of candies that Monocarp needs to buy additionally so that he can give each of the three nephews the same number of candies.

Example
InputCopy
2
7
24
OutputCopy
2
0
Note
In the first example, Monocarp needs to buy 2
 candies. After that, he will have 9
 candies, and he can give each of the three nephews 3
 candies.

In the second example, Monocarp does not need to buy any candies, as he initially has 24
 candies, and he can give each of the three nephews 8
 candies.
*/
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