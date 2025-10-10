/*
Mô tả
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, M;
vector<int> a;
int res = 0;

void input()
{
    cin >> n >> M;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void output()
{
    int left = 0, right = n - 1;
    sort(a.begin(), a.end());

    while (left < right)
    {
        if (a[left] + a[right] == M)
        {
            res++;
            left++;
            right--;
        }
        else if (a[left] + a[right] > M)
        {
            right--;
        }
        else if (a[left] + a[right] < M)
        {
            left++;
        }
    }

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