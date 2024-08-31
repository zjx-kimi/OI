#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

const int MAX_K = 800;
const int MAX_N = 4000;

int n, k, x, sum[MAX_N + 5][MAX_N + 5];
int dp[MAX_K + 5][MAX_N + 5];
int Calc(int u, int v) {
    return sum[v][v] - sum[v][u - 1] - sum[u - 1][v] + sum[u - 1][u - 1];
}

void dfs(int s, int L, int R, int optl, int optr) {
    if (L > R) return;
    int Mid = (L + R) / 2, opt;
    dp[s][Mid] = INF;
    for (int i = optl; i <= min(optr, Mid); i++) {
        if (dp[s][Mid] > dp[s - 1][i - 1] + Calc(i, Mid)) {
            dp[s][Mid] = dp[s - 1][i - 1] + Calc(i, Mid);
            opt = i;
        }
    }
    dfs(s, L, Mid - 1, optl, opt);
    dfs(s, Mid + 1, R, opt, optr);
}

int main() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            cin >> x;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
        }

    for (int i = 1; i <= n; i++)
        dp[0][i] = INF;
    for (int i = 1; i <= k; i++)
        dfs(i, 1, n, 1, n);

    cout << dp[k][n] / 2 << endl;
    
    return 0;
}
