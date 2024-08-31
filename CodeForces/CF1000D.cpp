#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
const int mod = 998244353;
int n, arr[N], c[N][N], dp[N], ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= n; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    dp[n + 1] = 1;
    for (int i = n; i >= 1; i--)
        if (arr[i] > 0)
            for (int j = i + arr[i] + 1; j <= n + 1; j++)
                (dp[i] += c[j - i - 1][arr[i]] * dp[j] % mod) %= mod;
    for (int i = 1; i <= n; i++) (ans += dp[i]) %= mod;
    cout << ans << '\n';
    return 0;
}