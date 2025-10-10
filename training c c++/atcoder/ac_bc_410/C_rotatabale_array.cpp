/*
Có một chuỗi số nguyên A có độ dài N, ban đầu Ai = i. Xử lý tổng cộng Q truy vấn theo các kiểu sau:

Kiểu 1: Đổi Ap thành x.

Kiểu 2: Đầu ra Ap.

Kiểu 3: Lặp lại thao tác "di chuyển phần tử đầu tiên của A đến cuối" k lần.

Về mặt hình thức, thay thế A bằng (A2 ,A3 ,…,AN ,A1 ) k lần.

Ràng buộc

Tất cả các giá trị đầu vào đều là số nguyên.

1≤N≤10^6

1≤Q≤3×10^5

Tất cả các truy vấn đều thỏa mãn các ràng buộc sau:

1≤p≤N

1≤x≤10^6

1≤k≤10^9

Đầu vào

Đầu vào được đưa ra từ Đầu vào chuẩn theo định dạng sau:

N Q
Query1
Query2
⋮
QueryQ

Tại đây, Queryi biểu diễn truy vấn thứ i.

Các truy vấn loại 1 được đưa ra theo định dạng sau:

1 p x

Các truy vấn loại 2 được đưa ra theo định dạng sau:

2 p

Các truy vấn loại 3 được đưa ra theo định dạng sau:

3 k

Đầu ra

Đối với mỗi truy vấn loại 2, hãy đưa ra câu trả lời trên một dòng.

Đầu vào mẫu 1

5 5
2 3
1 2 1000000
3 4
2 2
2 3

Đầu ra mẫu 1

3
1
1000000

Đầu vào này chứa 5 truy vấn.

Ban đầu, A=(1,2,3,4,5)

Truy vấn thứ nhất là Loại 2: đầu ra A3 =3.

Truy vấn thứ 2 là Loại 1: thay thế A2 bằng 1000000.

Sau truy vấn, A=(1,1000000,3,4,5).

Truy vấn thứ 3 là Loại 3: lặp lại thao tác "di chuyển phần tử đầu tiên của A đến cuối" 4 lần.

Sau truy vấn, A=(5,1,1000000,3,4).

Truy vấn thứ 4 là Loại 2: đầu ra A2 =1.

Truy vấn thứ 5 là Loại 2: đầu ra A3 = 1000000.
*/

#include <iostream>
#include <vector>

using namespace std;

int N, Q;
int query;
int p, x, k;

vector<int> A;
vector<int> res;
int offset = 0; // điểm khởi đầu vector

void solve(int query)
{
    if (query == 1)
    {
        cin >> p >> x;
        A[(p + offset - 1) % N] = x;
    }
    else if (query == 2)
    {
        cin >> p;
        res.push_back(A[(p + offset - 1) % N]);
    }
    else if (query == 3)
    {
        cin >> k;
        // giả lập thao tác xoay bằng cách tính lại offset
        offset = (offset + k) % N;
    }
}

void input()
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        A.push_back(i + 1);
    }

    while (Q--)
    {
        cin >> query;
        solve(query);
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
    cin.tie(nullptr);

    input();

    output();

    return 0;
}

// lazy rotation, tạo mảng logic bằng cách thay đổi offset còn mảng thực tế thì không đổi
// 23/06/2025