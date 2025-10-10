/*
Mô tả
A Rectangle of size n x mis divided into unit-square 1 x 1 with two colors black and white. The rectangle is represented by a matrix A(nx m) in which A(i, j) = 1 means that the unit-square at row i, column jis black and A(i, j) = 0 means that the unit-square at row icolumn jis white.
Find the sub-rectangle of the given rectangle containing only black unit-squares such that the area is maximal.
Input
•Line 1: contains 2 positive integers nand m(1 <= n, m<= 1000)
•Line i+1 (i= 1,…, n): contains the ith of the matrix A
Output
Write the area of the sub-rectangle found.

Example
Input
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
Output
6
---------------------------
Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
Dữ liệu
· Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
· Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
Kết quả
· Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
Ví dụ
Dữ liệu
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
Kết quả
6
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector<vector<int>> rec;
int res = 0;

vector<vector<int>> histogram;
vector<vector<int>> his_r; // vị trí mở rộng nhiều nhất về bên phải
vector<vector<int>> his_l; // vị trí mở rộng nhiều nhất về bên trái

void input()
{
    cin >> n >> m;
    rec.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rec[i][j];
        }
    }
}

void solve()
{
    // buld histogram
    histogram.resize(n, vector<int>(m));

    for (int j = 0; j < m; j++)
    {
        histogram[0][j] = rec[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rec[i][j] == 0)
            {
                histogram[i][j] = 0;
            }
            else
            {
                histogram[i][j] = histogram[i - 1][j] + 1;
            }
        }
    }

    // compute max sub-rec
    stack<int> s;
    his_r.resize(n, vector<int>(m));
    his_l.resize(n, vector<int>(m));

    // compute his_l
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // duy trì độ cao tăng ngặt
            while (!s.empty() && histogram[i][j] <= histogram[i][s.top()])
            {
                s.pop();
            }
            his_l[i][j] = (s.empty()) ? 0 : s.top() + 1;
            s.push(j);
        }

        while (!s.empty())
            s.pop();
    }

    // cout << ((s.empty()) ? "NULL" : to_string(s.top()));

    // compute his_r
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            // duy trì độ cao tăng ngặt
            while (!s.empty() && histogram[i][j] <= histogram[i][s.top()])
            {
                s.pop();
            }
            his_r[i][j] = (s.empty()) ? m - 1 : s.top() - 1;
            s.push(j);
        }

        while (!s.empty())
            s.pop();
    }

    // cout << ((s.empty()) ? "NULL" : to_string(s.top()));

    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << his_r[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << his_l[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // compute max area
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, histogram[i][j] * (his_r[i][j] - his_l[i][j] + 1));
        }
    }

    cout << res;
}

void output()
{
    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>

// using namespace std;

// vector<vector<int>> matrix, histogram;

// // Xây histogram từ ma trận nhị phân
// void buildHistogram(int n, int m) {
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 1)
//                 histogram[i][j] = histogram[i - 1][j] + 1;
//         }
//     }
// }

// // Tính mảng leftSmall hoặc rightSmall cho từng hàng
// void computeLeftRightSmall(const vector<int>& row, vector<int>& left, vector<int>& right) {
//     int m = row.size();
//     stack<int> st;

//     // Left Small
//     for (int i = 0; i < m; i++) {
//         while (!st.empty() && row[st.top()] >= row[i]) st.pop();
//         left[i] = st.empty() ? 0 : st.top() + 1;
//         st.push(i);
//     }

//     while (!st.empty()) st.pop();

//     // Right Small
//     for (int i = m - 1; i >= 0; i--) {
//         while (!st.empty() && row[st.top()] >= row[i]) st.pop();
//         right[i] = st.empty() ? m - 1 : st.top() - 1;
//         st.push(i);
//     }
// }

// // Tính hình chữ nhật lớn nhất trong histogram 2D
// int maxRectangleHistogram2D(int n, int m) {
//     int maxArea = 0;

//     for (int i = 0; i < n; i++) {
//         const auto& row = histogram[i];
//         vector<int> left(m), right(m);
//         computeLeftRightSmall(row, left, right);

//         for (int j = 0; j < m; j++) {
//             if (row[j] > 0) {
//                 int width = right[j] - left[j] + 1;
//                 maxArea = max(maxArea, row[j] * width);
//             }
//         }
//     }

//     return maxArea;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     matrix.resize(n, vector<int>(m));
//     histogram.resize(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++)
//             cin >> matrix[i][j];

//     histogram[0] = matrix[0]; // dòng đầu giữ nguyên
//     buildHistogram(n, m);

//     cout << maxRectangleHistogram2D(n, m) << '\n';
//     return 0;
// }
