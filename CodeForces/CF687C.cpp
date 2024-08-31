#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, ans;
int a[N];
bool dp[N][N][N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] |= dp[i - 1][j][k];
                if (j >= a[i]) 
                    dp[i][j][k] |= dp[i - 1][j - a[i]][k];
                if (j >= a[i] && k >= a[i])
                    dp[i][j][k] |= dp[i - 1][j - a[i]][k - a[i]];
            }
        }
    }
    for (int i = 0; i <= m; i++) ans += dp[n][m][i];
    cout << ans << '\n';
    for (int i = 0; i <= m; i++) if (dp[n][m][i]) cout << i << ' ';
    return 0;
}
/*
6 18
5 6 1 10 12 2


16
0 1 2 3 5 6 7 8 10 11 12 13 15 16 17 18 
*/