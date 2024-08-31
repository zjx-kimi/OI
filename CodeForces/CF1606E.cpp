#include <iostream>
using namespace std;
const int MOD = 998244353;
long long f[505][505], c[505][505];
long long fpow(long long x, int y) {
    long long ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}
int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i <= n; i++) c[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    for (int i = 2; i <= n; i++) // 还剩下一个人的情况显然不符合题意
        for (int j = 1; j <= x; j++) {
            if (i > j) {
                f[i][j] = ((fpow(j, i) - fpow(j - 1, i)) % MOD + MOD) % MOD;
            } else {
                for (int k = 1; k <= i; k++) {
                    f[i][j] = (f[i][j] + c[i][k] * fpow(i - 1, i - k) % MOD * f[k][j - i + 1]) % MOD;
                }
            }
        }
    long long ans = 0;
    for (int i = 1; i <= x; i++) ans = (ans + f[n][i]) % MOD;
    cout << ans << endl;
    return 0;
}