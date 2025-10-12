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
int N;
vector<int> hk;
vector<int> wk;

vector<vector<bool>> material;
bool complete = false;

void input()
{
    cin >> H >> W;
    cin >> N;
    hk.resize(N);
    wk.resize(N);
    material.resize(H, vector<bool>(W));

    for (int i = 0; i < N; i++)
    {
        cin >> hk[i] >> wk[i];
    }
}

void cutOrUnCutMaterial(int i, int j, int height, int width, bool s)
{
    for (int m = i; m < i + height; m++)
    {
        for (int n = j; n < j + width; n++)
        {
            material[m][n] = s;
        }
    }
}

bool check(int i, int j, int height, int width)
{
    if (i + height > H || j + width > W)
    {
        return false;
    }

    for (int m = i; m < i + height; m++)
    {
        for (int n = j; n < j + width; n++)
        {
            if (material[m][n] == true)
            {
                return false;
            }
        }
    }

    return true;
}

void solve(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        int h_k = hk[k], w_k = wk[k];

        // rotate
        if (i == 1)
        {
            h_k = wk[k];
            w_k = hk[k];
        }

        for (int m = 0; m < H - h_k + 1; m++)
        {
            for (int n = 0; n < W - w_k + 1; n++)
            {
                if (check(m, n, h_k, w_k))
                {
                    cutOrUnCutMaterial(m, n, h_k, w_k, true);

                    if (k == N - 1)
                    {
                        complete = true;
                        return;
                    }
                    else
                    {
                        solve(k + 1);

                        if (complete)
                        {
                            return;
                        }
                        else
                        {
                            cutOrUnCutMaterial(m, n, h_k, w_k, false);
                        }
                    }
                }
            }
        }
    }
}

void output()
{
    solve(0);
    cout << ((complete == true) ? 1 : 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}