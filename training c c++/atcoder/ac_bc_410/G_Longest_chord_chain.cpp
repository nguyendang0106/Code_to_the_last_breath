/*
Problem Statement

There are 2N pairwise distinct points, numbered from 1 to 2N, on a circle. Starting from point 1 and going clockwise, the points are arranged as point 2, point 3, ..., point 2N.

You are given N chords on this circle. The endpoints of the i-th chord are points Ai  and Bi , and the 2N values A1 ,…,AN ,B1 ,…,BN  are all distinct.

Perform the following operations on this circle once each in order:

Among the N chords on the circle, choose any number of chords such that no two chosen chords intersect, and delete the remaining chords.

Add one chord freely to the circle.

Find the maximum possible number of intersection points between chords after the operations are completed.

Constraints

1≤N≤2×10^5

1≤Ai ,Bi ≤2N

The 2N values A1 ,…,AN ,B1 ,…,BN  are pairwise distinct.

All input values are integers.



Input

The input is given from Standard Input in the following format:

N
A1  B1
A2  B2
⋮
AN  BN


Output

Output the answer.



Sample Input 1

3
1 5
6 3
4 2

Sample Output 1

2


Initially, there are 3 chords on the circle, as shown in the figure.
After deleting the chord connecting points 3 and 6 and adding a new chord through the operations, the number of intersection points between chords is 2.

Figure

It is impossible to make the number of intersection points between chords 3 or more, so the answer is 2.

The endpoints of the chord added at the end do not need to be any of the points 1,…,2N.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B;
int res = 0;

vector<pair<int, int>> interval; // lưu chuỗi 2N đoạn
vector<int> lis_dp;              // lis_dp[i] : giá trị của phần tử nhỏ nhất mà chuỗi dài i + 1 có thể kết thúc

void input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        interval.push_back({min(A, B), max(A, B)});
        interval.push_back({max(A, B), min(A, B) + 2 * N});
    }
}

void solve()
{
    sort(interval.begin(), interval.end(), [&](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    for (vector<pair<int, int>>::iterator it_1 = interval.begin(); it_1 != interval.end(); it_1++)
    {
        vector<int>::iterator it_2 = lower_bound(lis_dp.begin(), lis_dp.end(), (*it_1).first);

        if (it_2 == lis_dp.end()) // (*it_1).first > tất cả các phần tử hiện có trong lis_dp
        {
            lis_dp.push_back((*it_1).first);
        }
        else // nếu trong lis_dp có phần tử nào >= (*it_1).first thì thay thế
        {
            (*it_2) = (*it_1).first;
        }
    }

    res = lis_dp.size();
}

void output()
{
    solve();
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

// "Tìm k lớn nhất, với k là số lượng dây cung không giao nhau có thể chọn được từ N dây cung ban đầu."
// Từ N dây cung -> 2N đoạn thẳng, dây (Ai, Bi) -> [Ai, Bi] và [Bi, Ai + 2N]
// Sắp xếp các đoạn với Bi giảm dần
// Tìm dãy con tăng dài nhất tăng dài nhất
// 03/10/2025