/*
Monocarp has a deck of cards numbered from 1
 to 𝑛
. Initially, the cards are arranged from smallest to largest, with 1
 on top and 𝑛
 at the bottom.

Monocarp performed 𝑘
 actions on the deck. Each action was one of three types:

remove the top card;
remove the bottom card;
remove either the top or bottom card.
Your task is to determine the fate of each card: whether it remains in the deck, has been removed, or might be both.

Input
The first line contains a single integer 𝑡 (1≤𝑡≤10^4) — the number of test cases.

The first line of each test case contains two integers 𝑛 and k (1≤𝑘≤𝑛≤2⋅10^5).

The second line contains a string 𝑠
 of length 𝑘
, consisting of characters 0, 1, and/or {2}. This string describes Monocarp's actions. If the 𝑖
-th character is 0, Monocarp removes the top card on the 𝑖
-th action. If it's 1, he removes the bottom card. If it's 2, either the top or bottom card can be removed.

Additional constraint on the input: the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print a string consisting of 𝑛
 characters. The 𝑖
-th character should be + (plus sign) if the 𝑖
-th card is still in the deck, - (minus sign) if it has been removed, or ? (question mark) if its state is unknown.

Example
InputCopy
4
4 2
01
3 2
22
1 1
2
7 5
01201
OutputCopy
-++-
???
-
--?+?--
*/
#include <iostream>
#include <vector>

using namespace std;

int t;
int n, k;
string tmp;

void solve(int a, int b, string c)
{
}

void input()
{
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        cin >> tmp;
        solve(n, k, tmp);
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