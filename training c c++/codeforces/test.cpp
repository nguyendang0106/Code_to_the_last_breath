#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int T;
int N;
string S;

vector<int> res;

void solve(int n, string s)
{
    vector<int> array(2 * n + 1, -11);                                           // chỉ số xuất hiện cuối cùng của prefix sum
    int sum_s = count(s.begin(), s.end(), 'a') - count(s.begin(), s.end(), 'b'); // số phần tử chênh lệch của a và b -> cần xoá đi sum_s phần tử để chuỗi cân bằng

    if (sum_s == 0 || sum_s == n || sum_s == -n)
    {
        res.push_back(sum_s == 0 ? 0 : -1);
        vector<int>().swap(array);
        return;
    }

    array[0 + n] = -1;
    int h = 0; // lưu prefix sum
    int ans = n;

    forn(i, n)
    {
        h += s[i] == 'a' ? 1 : -1;
        array[h + n] = i;

        // array[h + n]: chỉ số của prefix sum của m phần tử đầu tiên -> [0, m - 1]
        // array[h + n - sum_s]: chỉ số của prefix sum của x phần tử đầu tiên -> [0, x - 1]
        // sum_s = m - x

        if (array[h + n - sum_s] != -11) // đã tồn tại
        {
            ans = min(ans, i - (array[h + n - sum_s] + 1) + 1); // xoá đi [x, m - 1]
        }
    }

    res.push_back(ans == n ? -1 : ans);

    // giải phóng
    vector<int>().swap(array);
}

void input()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cin >> S;
        solve(N, S);
    }
}

void output()
{
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
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
}

// đưa về bài toán tìm đoạn con ngắn nhất có tổng bằng s độ phức tạp O(n) hoặc O(nlog(n))