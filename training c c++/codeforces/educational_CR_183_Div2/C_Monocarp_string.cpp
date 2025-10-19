/*
Monocarp has a string 𝑠 of length 𝑛, consisting of the letters 'a' and 'b'. He wants to remove some (possibly zero) number of consecutive letters from his string in such a way that the number of letters 'a' and 'b' in the resulting string becomes equal. Monocarp can start removing letters from any position in the string 𝑠.
Monocarp really likes his string 𝑠, so he wants to remove as few consecutive letters from it as possible.
Your task is to determine the minimum number of consecutive letters from the string 𝑠 that need to be removed so that the number of letters 'a' and 'b' in the resulting string becomes equal. If it is necessary to remove all letters from the string 𝑠 (i.e., make it empty), report this.
Input
The first line contains one integer 𝑡 (1≤𝑡≤10^4) — the number of test cases.
Each test case consists of two lines:
the first line contains one integer 𝑛 (2≤𝑛≤2⋅10^5) — the number of characters in the string 𝑠;
the second line contains the string 𝑠 of length 𝑛, consisting of the letters 'a' and/or 'b'.
Additional constraint on the input: the sum of values of 𝑛 over all test cases does not exceed 2⋅10^5.
Output
For each test case, print the answer as follows:
If in order to make the number of letters 'a' and 'b' equal, it is necessary to remove all letters from the string 𝑠, output −1.
Otherwise, output the minimum number of consecutive letters that Monocarp needs to remove from his string 𝑠 so that the number of letters 'a' and 'b' becomes equal.
Example
Input
Copy
5
5
bbbab
6
bbaaba
4
aaaa
12
aabbaaabbaab
5
aabaa
Output
Copy
3
0
-1
2
-1
Note
In the first example, Monocarp needs to remove the first three letters from his string. After that, his string will become "ab". In this string, there is one letter 'a' and one letter 'b'.
In the second example, the given string has three letters 'a' and three letters 'b', so nothing needs to be removed.
In the third example, all letters of the string need to be removed, as there are no letters 'b', so −1 should be printed.
In the fourth example, Monocarp can, for example, remove the fifth and sixth letters from his string. Then his string will become "aabbabbaab". In this string, there are five letters 'a' and five letters 'b'.
In the fifth example, all letters of the string need to be removed to make the number of letters 'a' and 'b' equal, so −1 should be printed.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

int T;
int N;
string S;

vector<int> res;

void solve(int n, string s)
{
    // chuyển string s sang dãy 1, -1
    vector<int> convert_s;
    for (string::iterator it = s.begin(); it != s.end(); it++)
    {
        if ((*it) == 'a')
        {
            convert_s.push_back(1);
        }
        else
        {
            convert_s.push_back(-1);
        }
    }

    // tính prefixsum của string s
    vector<int> pfs_s;
    vector<int> array(2 * n + 1, -2); // đánh giấu vị trí đầu tiên xuất hiện của prefix sum

    int h = 0;
    pfs_s.push_back(0);
    array[0 + n] = -1;
    forn(i, n)
    {
        h += convert_s[i];
        pfs_s.push_back(h);
    }

    int sum_s = pfs_s[n];
    int min_subsequence = 1e9;

    if (sum_s == 0) // a == b
    {
        res.push_back(0);
    }
    else if (abs(sum_s) == n) // toàn a hoặc toàn b
    {
        res.push_back(-1);
    }
    else
    {
        // tìm đoạn ngắn nhất có tổng sum_s
        // pfs_s[r + 1] - pfs_s[l] = sum_s ([l, r])
        forn(i, n)
        {
            int target = pfs_s[i + 1] - sum_s;
            if (array[target + n] != -2)
            {
                min_subsequence = min(min_subsequence, i - array[target + n] - 1 + 1);
            }
            else
            {
                array[target + n] = i;
            }
        }

        // nếu min_subsequence = n -> phải xoá hết
        res.push_back(min_subsequence == n ? -1 : min_subsequence);
    }

    // giải phóng
    vector<int>().swap(convert_s);
    vector<int>().swap(pfs_s);
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