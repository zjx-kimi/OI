// Problem: E - Maximum Glutton
// Contest: atCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (atCoder beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_e
// Memory Limit: 1024 Mb
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N = 80;
const int M = 10005;
int n, x, y;
int dp[N][N][M];
int a[N], b[N];
int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i] >> b[i];
    for (int i = 0; i <= n; ++i)
    	for (int j = 0; j <= n; j++)
    		for (int k = 0; k <= x; k++)
    			dp[i][j][k] = 1e9;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= x; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j > 0 && k >= a[i]) {
                    int new_salty = dp[i - 1][j - 1][k - a[i]] + b[i];
                    if (new_salty <= y) {
                        dp[i][j][k] = min(dp[i][j][k], new_salty);
                    }
                }
            }
        }
    }

    int max_dishes = 0;
    for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= x; ++k) {
            if (dp[n][j][k] <= y) {
                max_dishes = max(max_dishes, j);
            }
        }
    }

    cout << min(n, max_dishes + 1) << endl;
    return 0;
}
