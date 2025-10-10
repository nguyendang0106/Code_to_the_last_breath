/*
Problem Statement

You are given an H×W grid, where each cell contains # or ..
The information about the symbols written in each cell is given as H strings S1 ,S2 ,…,SH  of length W, where the cell in the i-th row from the top and j-th column from the left contains the same symbol as the j-th character of Si .
Find the number of rectangular regions in this grid that satisfy all of the following conditions:

The number of cells containing # and the number of cells containing . in the rectangular region are equal.

Formally, find the number of quadruples of integers (u,d,l,r) that satisfy all of the following conditions:

1≤u≤d≤H

1≤l≤r≤W

When extracting the part of the grid from the u-th through d-th rows from the top and from the l-th through r-th columns from the left, the number of cells containing # and the number of cells containing . in the extracted part are equal.

You are given T test cases. Find the answer for each of them.

Constraints

1≤T≤25000

1≤H,W

The sum of H×W over all test cases in one input does not exceed 3×10^5.

Si  is a string of length W consisting of # and ..



Input

The input is given from Standard Input in the following format:

T
case1
case2
⋮
caseT


casei  represents the i-th test case. Each test case is given in the following format:

H W
S1
S2
⋮
SH


Output

Output T lines. The i-th line should contain the answer for the i-th test case.



Sample Input 1

3
3 2
##
#.
..
6 6
..#...
..#..#
#.#.#.
.###..
######
.###..
15 50
.......................#...........###.###.###.###
....................#..#..#..........#.#.#...#.#..
.................#...#####...#.....###.#.#.###.###
..................#..##.##..#......#...#.#.#.....#
...................#########.......###.###.###.###
....................#.....#.......................
.###........##......#.....#..#...#.####.####.##..#
#..#.........#......#.....#..#...#.#....#....##..#
#..#.........#......#.....#..#...#.#....#....##..#
#.....##...###..##..#.....#..#...#.#....#....#.#.#
#....#..#.#..#.#..#.#..##.#..#...#.####.####.#.#.#
#....#..#.#..#.####.#....##..#...#.#....#....#.#.#
#....#..#.#..#.#....#.....#..#...#.#....#....#..##
#..#.#..#.#..#.#..#.#....#.#.#...#.#....#....#..##
.##...##...####.##...####..#..###..####.####.#..##


Sample Output 1

4
79
4032


This input contains 3 test cases.

For the 1st case, the following 4 rectangular regions satisfy the conditions in the problem statement:

From the 1st to 2nd rows from the top, from the 2nd to 2nd columns from the left

From the 2nd to 3rd rows from the top, from the 1st to 1st columns from the left

From the 2nd to 2nd rows from the top, from the 1st to 2nd columns from the left

From the 1st to 3rd rows from the top, from the 1st to 2nd columns from the left

*/

#include <iostream>
#include <vector>

using namespace std;

int T, H, W;
vector<string> S;

vector<long long> res;
vector<int> C;
vector<int> bk; // bk[x] = y => prefix sum x đã gặp y lần

vector<string> flip(vector<string> &s)
{
    int h = s.size(), w = s[0].size();
    vector<string> flip_s(w);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            flip_s[j] += s[i][j];
        }
    }

    return flip_s;
}

void solve()
{
    H = S.size();
    W = S[0].size();

    bk.assign(2 * H * W + 1, 0); // tổng giá trị của prefix sum thuộc [-H * W, H * W] (tổng giá trị của cả ma trận)

    int ofs = H * W;
    long long cnt = 0;

    // process
    for (int u = 0; u < H; u++)
    {
        C.assign(W, 0);

        for (int d = u; d < H; d++)
        {
            // tạo mảng 1D
            for (int i = 0; i < W; i++)
            {
                if (S[d][i] == '#')
                {
                    C[i]++;
                }
                else
                {
                    C[i]--;
                }
            }

            int h = 0;     // lưu prefix sum
            bk[h + ofs]++; // khởi tạo coi như prefix sum = 0 đã gặp 1 lần rồi (coi như khởi tạo ở vị trí -1 trong pre_C)
            for (int i = 0; i < W; i++)
            {
                h += C[i];
                cnt += bk[h + ofs];
                bk[h + ofs]++;
            }

            // reset bk
            h = 0;
            bk[h + ofs] = 0;
            for (int i = 0; i < W; i++)
            {
                h += C[i];
                bk[h + ofs] = 0;
            }
        }
    }

    res.push_back(cnt);
}

void input()
{
    cin >> T;
    while (T--)
    {
        cin >> H >> W;
        S.assign(H, "");
        for (int i = 0; i < H; i++)
        {
            cin >> S[i];
        }

        if (H > W)
        {
            S = flip(S);
        }

        solve();
    }
}

void output()
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
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

// 26/09/2025