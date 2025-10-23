/*
A permutation of length 𝑛 is an array of 𝑛 integers, where each number from 1 to 𝑛 appears exactly once. An inversion in a permutation 𝑝 is a pair of indices (𝑖,𝑗) such that 𝑖<𝑗 and 𝑝𝑖>𝑝𝑗.
For a permutation 𝑝, we define its inversion value as the number of its subsegments that contain at least one inversion. Formally, this is the number of pairs of integers (𝑙,𝑟) (1≤𝑙<𝑟≤𝑛) for which there exists a pair of indices (𝑖,𝑗) satisfying the following conditions: 𝑙≤𝑖<𝑗≤𝑟 and 𝑝𝑖>𝑝𝑗.
For example, for the permutation [3,1,4,2], the inversion value is 5.
You are given two integers 𝑛 and 𝑘. Your task is to construct a permutation of length 𝑛 with an inversion value equal to exactly 𝑘.
Input
The first line contains one integer 𝑡 (1≤𝑡≤500) — the number of test cases.
Each test case consists of a single line containing two integers 𝑛 and 𝑘 (2≤𝑛≤30; 0≤𝑘≤𝑛(𝑛−1)2).
Output
For each test case, output the answer as follows:
if the desired permutation does not exist, output a single integer 0;
otherwise, output 𝑛 distinct integers from 1 to 𝑛 — the desired permutation. If there are multiple such permutations, you may output any of them.
Example
Input
Copy
5
4 5
5 10
5 0
6 8
3 1
Output
Copy
3 1 4 2
5 4 3 2 1
1 2 3 4 5
2 3 5 6 1 4
0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)

int T, N, K;
vector<vector<int>> res;

void solve(int n, int k)
{
    vector<int> tmp;

    // process

    res.push_back(tmp);
    vector<int>().swap(tmp);
}

void input()
{
    cin >> T;
    forn(i, T)
    {
        cin >> N >> K;
        solve(N, K);
    }
}

void output()
{
    cout << endl;
    for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++)
    {
        for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            cout << (*it2) << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();
}