#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 205;
int n, k, ans = 0, sum = 0;
int a[N], dp[2][N][12000];
int Get(int x, int p) {
    int count = 0;
    while (x % p == 0) {
        x /= p;
        count++;
    }
    return count;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int num_two = Get(a[i], 2);
        int num_five = Get(a[i], 5);
        int cur = i % 2;
        sum += num_two;

        for (int j = 0; j <= k && j <= i; j++) {
            for (int x = 0; x <= sum; x++) {
                dp[cur][j][x] = dp[cur ^ 1][j][x];
                if (j >= 1 && x - num_two >= 0 && dp[cur ^ 1][j - 1][x - num_two] >= 0) {
                    dp[cur][j][x] = max(dp[cur][j][x], dp[cur ^ 1][j - 1][x - num_two] + num_five);
                }
            }
        }
    }

    for (int i = 0; i <= sum; i++) {
        ans = max(ans, min(i, dp[(n % 2)][k][i]));
    }
    printf("%lld", ans);
    return 0;
}