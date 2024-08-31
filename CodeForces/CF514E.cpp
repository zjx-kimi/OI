#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
struct matrix {
    int x, y, a[110][110];
    matrix() {};
    matrix(int xx, int yy)
        : x(xx)
        , y(yy) { memset(a, 0, sizeof(a)); }
} s;
int n, x, cnt[120], sum[120], dp[120];
matrix mul(matrix A, matrix B) {
    matrix C = (matrix) { A.x, B.y };
    for (int i = 1; i <= A.x; i++)
        for (int j = 1; j <= B.y; j++)
            for (int k = 1; k <= B.x; k++)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
    return C;
}
inline void init() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
   }
    dp[0] = 1, sum[0] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= i; j++)
            dp[i] = (dp[i] + dp[i - j] * cnt[j]) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    s.x = 101, s.y = 101;
    for (int i = 1; i <= 99; i++)
        s.a[i + 1][i] = 1, s.a[i][100] = cnt[101 - i], s.a[i][101] = cnt[101 - i];
    s.a[100][100] = s.a[100][101] = cnt[1], s.a[101][101] = 1;
}
matrix qpow(matrix s, int b) {
    matrix C = (matrix) { s.x, s.y };
    for (int i = 1; i <= 101; i++) C.a[i][i] = 1;
    while (b) {
        if (b & 1) C = mul(C, s);
        b >>= 1;
        s = mul(s, s);
    }
    return C;
}
signed main() {
    init();
    matrix A = (matrix) { 1, 101 };
    for (int i = 1; i <= 100; i++)
        A.a[1][i] = dp[i];
    A.a[1][101] = sum[100];
    if (x <= 100) {
        printf("%lld\n", sum[x]);
        return 0;
    }
    A = mul(A, qpow(s, x - 100));
    printf("%lld\n", A.a[1][101] % mod);
    return 0;
}