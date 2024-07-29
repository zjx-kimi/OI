#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m;
int arr[N][N];
int dp[N][N][N][N];
int max(int a, int b, int c, int d) {
    int m = max(a, b), n = max(c, d);
    return max(m, n);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &arr[i][j]);
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= m; y1++) {
            for (int x2 = x1 + 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 < y1; y2++) {
                    dp[x1][y1][x2][y2] = max(
                        dp[x1 - 1][y1][x2 - 1][y2], 
                        dp[x1 - 1][y1][x2][y2 - 1], 
                        dp[x1][y1 - 1][x2 - 1][y2], 
                        dp[x1][y1 - 1][x2][y2 - 1] 
                    ) + arr[x1][y1] + arr[x2][y2];
                }
            }
        }
    }
    cout << dp[n - 1][m][n][m - 1];
}