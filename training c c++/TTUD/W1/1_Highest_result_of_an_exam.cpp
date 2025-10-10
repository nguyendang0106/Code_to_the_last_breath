/*
Mô tả
The result of an exam of a contest is represented by the sequence of integers a[1], a[2], . . ., a[n] in which a[i] is the point of the participant i (i = 1, . . ., n).
Find the highgest point of the exam.
Input
Line 1: contains a positive integer n (1 <= n <= 1000)
Line 2: contains a[1], a[2], . . ., a[n] (0 <= a[i] <= 1000)
Output
Write the highest point
Example
Input
5
3 2 0 8 4
Output
8
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

int res = 0;

void input()
{
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] > res)
            res = a[i];
    }
}

void output()
{
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}