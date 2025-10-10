/*
Có một đồ thị có hướng với N đỉnh và M cạnh, trong đó các đỉnh được đánh số từ 1 đến N và các cạnh được đánh số từ 1 đến M. Cạnh i là cạnh có hướng từ đỉnh Ai đến đỉnh Bi với trọng số Wi .

Tìm giá trị nhỏ nhất của bitwise XOR của trọng số các cạnh được bao gồm trong một lần đi từ đỉnh 1 đến đỉnh N.

- Đi từ đỉnh 1 đến đỉnh N là gì?

Theo trực giác, đó là "một đường đi từ đỉnh 1 đến đỉnh N có thể đi qua cùng một đỉnh hoặc cạnh nhiều lần". Về mặt hình thức, đó là một chuỗi các cạnh (e1 ,…,ek ) thỏa mãn tất cả các điều kiện sau:

e1 bắt đầu tại đỉnh 1.

Với mọi 1≤i<k, điểm cuối của ei và điểm bắt đầu của ei+1 là giống nhau.

ek kết thúc tại đỉnh N.

- Phép toán bitwise XOR là gì?

XOR bitwise của các số nguyên không âm A và B, được ký hiệu là A XOR B, được định nghĩa như sau:

Khi A XOR B được viết ở dạng nhị phân, chữ số ở vị trí thứ 2k (k≥0) là 1 nếu chính xác một trong các chữ số ở vị trí thứ 2k của A và B trong dạng nhị phân là 1 và 0 nếu không.

Ví dụ: 3 XOR 5=6 (ở dạng nhị phân: 011 XOR 101=110).

Nhìn chung, XOR bitwise của k số nguyên không âm p1 ,p2 ,p3 ,…,pk được định nghĩa là

(…((p1 XOR p2 ) XOR p3 ) XOR … XOR pk ), và có thể chứng minh rằng điều này không phụ thuộc vào thứ tự của p1 ,p2 ,p3 ,…pk .

Ràng buộc

2≤N≤1000

0≤M≤1000

1≤Ai,Bi≤N

0≤Wi<2^10

Tất cả các giá trị đầu vào đều là số nguyên.

Đầu vào

Đầu vào được đưa ra từ Đầu vào chuẩn theo định dạng sau:

N M

A1 B1 W1

A2 B2 W2

⋮

AM BM WM

Đầu ra

Nếu không có bước đi nào từ đỉnh 1 đến đỉnh N, đầu ra là -1.

Nếu có bước đi từ đỉnh 1 đến đỉnh N, đầu ra là giá trị nhỏ nhất của XOR bitwise của trọng số của các cạnh được bao gồm trong bước đi đó.

Đầu vào mẫu 1

3 3

1 2 4

2 3 5

1 3 2

Đầu ra mẫu 1

1

Phép XOR bitwise của trọng số các cạnh được bao gồm trong quá trình đi bộ (cạnh 1, cạnh 2) là 1.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 1000;
const int MAXX = 1023; // vì Wi < 2^10 nên XOR lớn nhất có thể tạo ra là 2^10 - 1 = 1023 (2^k - 1 với k là số bit tối đa trong một số)

int N, M;
int a, b, w;
vector<vector<pair<int, int>>> G; // G[u] = {v, w}
vector<vector<int>> visited;      // visited [u] = {s}

void input()
{
    cin >> N >> M;
    G.resize(N + 1);
    visited.resize(N + 1, vector<int>(MAXX + 1));

    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b >> w;
        G[a].emplace_back(b, w); // directed graph
    }
}

// BFS
void solve()
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1][0] = 1;

    while (!q.empty())
    {
        auto [u, u_xor] = q.front();
        q.pop();

        for (auto [v, w] : G[u])
        {
            if (visited[v][u_xor ^ w])
                continue;

            q.push({v, u_xor ^ w});
            visited[v][u_xor ^ w] = 1;
        }
    }

    int ans = -1;
    for (int i = 0; i <= MAXX; i++)
    {
        if (visited[N][i])
        {
            ans = i;
            break;
        }
    }

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solve();

    return 0;
}

/*
  PHÂN TÍCH CHI TIẾT THUẬT TOÁN:

  1. VERTEX MULTIPLEXING:
     - Mỗi state là (vertex, xor_value)
     - State (u, s) = "đến đỉnh u với tổng XOR = s"
     - Từ (u, s) có thể đi đến (v, s⊕w) nếu có cạnh u→v trọng số w

  2. BFS TRÊN KHÔNG GIAN STATE:
     - Bắt đầu từ (1, 0): đỉnh 1 với XOR = 0
     - Mỗi lần explore một state (u, s), thêm tất cả state có thể đạt được
     - visited[v][new_xor] = true để tránh thăm lại state đã xét

  3. TẠI SAO THUẬT TOÁN ĐÚNG:
     - BFS đảm bảo thăm state theo thứ tự tăng dần của số bước
     - Với mỗi đỉnh N, ta tìm được TẤT CẢ giá trị XOR có thể đạt được
     - Giá trị XOR nhỏ nhất trong số đó chính là đáp án

  4. XỬ LÝ CHU TRÌNH:
     - Chu trình được xử lý tự động thông qua việc thăm lại đỉnh với XOR khác
     - Nếu có chu trình XOR = c, ta có thể từ state (u, s) đi đến (u, s⊕c)
     - Tất cả combination được explore đầy đủ

  5. COMPLEXITY:
     - Time: O((N + M) × 1024) = O((N + M) × maxWi)
     - Space: O(N × 1024) cho mảng visited
*/
// 26/07/2025
