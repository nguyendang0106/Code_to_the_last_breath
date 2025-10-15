#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int t;
int n, k;
string tmp;

vector<string> res;

void solve(int a, int b, string s)
{
    string tmp2(a, '+');
    unordered_map<char, int> count_actions;

    // process
    // đếm số thao tác cho từng hành động
    for (int i = 0; i < s.size(); i++)
    {
        count_actions[s[i]]++; // 0 : k0, 1 : k1, 2 : k2
    }

    // nếu n = k thì tất cả các lá bài đều bị xoá
    if (a == b)
    {
        fill(tmp2.begin(), tmp2.end(), '-');
    }
    else // n > k
    {
        // k0 lá đầu tiên bị loại bỏ [0, k0 - 1]
        fill(tmp2.begin(), tmp2.begin() + count_actions['0'], '-');

        // k1 lá cuối cùng bị loại bỏ [n - k1, n - 1]
        fill(tmp2.begin() + a - count_actions['1'], tmp2.begin() + a, '-');

        // [k0 + k2, n - k1 - k2 - 1] chắc chắn không bị loại bỏ
        // [k0, k0 + k2 - 1] và [n - k1 - k2, n - k1 - 1] không chắc chắn
        fill(tmp2.begin() + count_actions['0'], tmp2.begin() + count_actions['0'] + count_actions['2'], '?');

        fill(tmp2.begin() + a - count_actions['1'] - count_actions['2'], tmp2.begin() + a - count_actions['1'], '?');
    }

    res.push_back(tmp2);
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
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++)
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
