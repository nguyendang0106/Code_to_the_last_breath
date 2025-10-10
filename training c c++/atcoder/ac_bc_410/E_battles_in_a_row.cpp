/*
Bài toán

Takahashi sắp chơi một trò chơi, trong đó anh ta chiến đấu với N quái vật theo thứ tự. Ban đầu, máu của Takahashi là H và sức mạnh phép thuật của anh ta là M.

Đối với quái vật thứ i mà anh ta chiến đấu, anh ta có thể chọn một trong các hành động sau:

Chiến đấu mà không sử dụng phép thuật. Hành động này chỉ có thể được chọn khi máu của anh ta ít nhất là Ai, và máu của anh ta giảm đi một lượng Ai và quái vật bị đánh bại.

Chiến đấu bằng phép thuật. Hành động này chỉ có thể được chọn khi sức mạnh phép thuật của anh ta ít nhất là Bi, và sức mạnh phép thuật của anh ta giảm đi một lượng Bi và quái vật bị đánh bại.

Trò chơi kết thúc khi tất cả N quái vật bị đánh bại hoặc khi anh ta không thể thực hiện bất kỳ hành động nào. Số lượng quái vật tối đa anh ta có thể đánh bại trước khi trò chơi kết thúc là bao nhiều?

Các ràng buộc

1≤N≤3000

1≤H,M≤3000

1≤Ai,Bi ≤3000

Tất cả các giá trị đầu vào đều là số nguyên.

Đầu vào
Đầu vào được cung cấp từ Đầu vào Chuẩn theo định dạng sau:

N H M
A1 B1
A2 B2
⋮
AN BN

Đầu ra
Đưa ra đáp án.

Sample input 1
4 10 14
5 8
5 6
7 9
99 99

Sample output 1
3

Bằng cách thực hiện các hành động sau, Takahashi có thể đánh bại 3 quái vật trước khi trò chơi kết thúc.

- Ban đầu, máu của anh ta là 10 và sức mạnh phép thuật là 14.

- Chiến đấu với quái vật thứ nhất mà không sử dụng phép thuật. Máu của anh ta giảm 5, còn máu là 5 và sức mạnh phép thuật là 14.

- Chiến đấu với quái vật thứ hai mà không sử dụng phép thuật. Máu của anh ta giảm 5, còn máu là 0 và sức mạnh phép thuật là 14.

- Chiến đấu với quái vật thứ ba bằng phép thuật. Sức mạnh phép thuật của anh ta giảm 9, còn máu là 0 và sức mạnh phép thuật là 5.

- Đối với quái vật thứ tư, anh ta không thể chọn bất kỳ hành động nào, vì vậy trò chơi kết thúc.
*/

/*
PHÂN TÍCH DP CHI TIẾT:

1. ĐỊNH NGHĨA STATE:
   DP[i][m] = lượng máu tối đa sau khi đánh bại i quái vật đầu tiên với sức mạnh phép thuật còn lại là m

2. TẠI SAO ƯU TIÊN TỐI ĐA HÓA MÁU?

   Trả lời: Về mặt lý thuyết, ta HOÀN TOÀN có thể thay đổi cách biểu diễn!

   Cách 1 (hiện tại): DP[i][m] = lượng máu tối đa với mana còn lại m
   Cách 2 (thay thế): DP[i][h] = lượng mana tối đa với máu còn lại h

   Công thức tương ứng:
   DP[i][h] = max(
       DP[i-1][h+A[i]],        // Option 1: Dùng máu (trước đó có h+A[i] máu)
       DP[i-1][h] - B[i]       // Option 2: Dùng mana (mất B[i] mana)
   )

3. LỰA CHỌN THIẾT KẾ:
   - Nếu H < M: tối đa hóa mana, state space nhỏ hơn O(N×H)
   - Nếu M < H: tối đa hóa máu, state space nhỏ hơn O(N×M)
   - Trong bài này H,M <= 3000: tương đương nhau

4. VAI TRÒ CỦA MÁU VÀ MANA LÀ TƯƠNG ĐƯƠNG
   Có thể tự do chọn tối đa hóa resource nào

5. CÔNG THỨC CHUYỂN ĐỔI (CÁCH HIỆN TẠI):
   DP[i][m] = max(
       DP[i-1][m] - A[i],      // Option 1: Không dùng phép thuật
       DP[i-1][m+B[i]]         // Option 2: Dùng phép thuật
   )

Base case: DP[0][M] = H
Đáp án: max{i | exists m: DP[i][m] >= 0}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 3000;

int N, H, M;
int A[MAXV + 1], B[MAXV + 1];

vector<vector<int>> dp; // dp[i][m] = h => số máu tối đa h còn lại sau khi đánh bại i quái vật đầu tiên và còn m mana

void input()
{
    cin >> N >> H >> M;
    dp.resize(N + 1, vector<int>(M + 1, -1));
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }
}

void solve()
{
    dp[0][M] = H; // base

    int ans = 0;
    int flag = 0;
    for (int i = 1; i <= N; i++)
    {
        flag = 0;

        for (int j = 0; j <= M; j++)
        {
            // dùng máu
            if (dp[i - 1][j] >= A[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - A[i]);
            }

            // dùng mana
            if (j + B[i] <= M && dp[i - 1][j + B[i]] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + B[i]]);
            }
        }

        for (int m = 0; m <= M; m++) // nếu có thể đạt được giá trị nào đó thì đây là số quái có thể đánh được
        {
            if (dp[i][m] >= 0)
            {
                ans = i;
                flag = 1;
                break;
            }
        }

        if (flag != 1)
        {
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
// 13/08/2025