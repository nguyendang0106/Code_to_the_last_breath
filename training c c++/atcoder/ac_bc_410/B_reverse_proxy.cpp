/*
Có N hộp được đánh số 1,2,…,N. Ban đầu, tất cả các hộp đều rỗng.

Q quả bóng sẽ theo thứ tự.
Takahashi sẽ đặt các quả bóng vào các hộp theo trình tự X=(X1,X2,…,XQ)
Cụ thể, anh ấy thực hiện quy trình sau cho quả bóng thứ i:

Nếu Xi≥1: Đặt quả bóng này vào hộp Xi .

Nếu Xi=0: Đặt quả bóng này vào hộp có số nhỏ nhất trong số các hộp chứa ít quả bóng nhất.

Tìm hộp mà mỗi quả bóng được đặt vào.

Ràng buộc

Tất cả các giá trị đầu vào đều là số nguyên.

1≤N≤100

1≤Q≤100

0≤Xi≤N

Đầu vào

Đầu vào được đưa ra từ Đầu vào chuẩn theo định dạng sau:

N Q
X1 X2 …… XQ

Đầu ra

Nếu quả bóng thứ i được đặt vào hộp Bi, đầu ra theo định dạng sau:

B1 B2 …… BQ

Đầu vào mẫu 1

4 5
2 0 3 0 0

Đầu ra mẫu 1

2 1 3 4 1

Có 4 hộp và có 5 quả bóng.

Ban đầu, tất cả các hộp đều rỗng.

Số lượng bóng trong hộp 1,2,3,4 lần lượt là 0,0,0,0.

Vì X1=2, bỏ quả bóng thứ nhất vào hộp 2.

Số bóng trong hộp 1,2,3,4 lần lượt là 0,1,0,0.

Vì X2=0, bỏ quả bóng thứ 2 vào hộp 1, hộp có số nhỏ nhất trong số những hộp chứa ít bóng nhất.

Số bóng trong hộp 1,2,3,4 lần lượt là 1,1,0,0.

Vì X3=3, bỏ quả bóng thứ 3 vào hộp 3.

Số bóng trong hộp 1,2,3,4 lần lượt là 1,1,1,0.

Vì X4=0, bỏ quả bóng thứ 4 vào hộp 4, hộp có số nhỏ nhất trong số những hộp chứa ít bóng nhất.

Số bóng trong hộp 1,2,3,4 lần lượt là 1,1,1,1.

Vì X5=0, hãy bỏ quả bóng thứ 5 vào hộp 1, hộp này có số lượng nhỏ nhất trong số các hộp chứa ít quả bóng nhất.

Số lượng quả bóng trong hộp 1,2,3,4 lần lượt là 2,1,1,1.

Các quả bóng được bỏ vào hộp 2,1,3,4,1 theo thứ tự. Do đó, đầu ra là 2 1 3 4 1.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> X;

vector<int> Box;
vector<int> res;

void input()
{
    cin >> N >> Q;
    X.resize(Q);
    Box.resize(N + 1);

    for (int i = 0; i < Q; i++)
    {
        cin >> X[i];
    }
}

void solve()
{
    for (int i = 0; i < Q; i++)
    {
        if (X[i] > 0)
        {
            Box[X[i]]++;
            res.push_back(X[i]);
        }
        else
        {
            int cur_min_box = *min_element(Box.begin() + 1, Box.end()); // giá trị nhỏ nhất trong các hộp O(N)
            for (int j = 1; j <= N; j++)
            {
                if (Box[j] == cur_min_box)
                {
                    Box[j]++;
                    res.push_back(j); // tìm và thêm hộp đó và res
                    break;
                }
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solve();

    return 0;
}

// duyệt có điều kiện
// 22/06/2025