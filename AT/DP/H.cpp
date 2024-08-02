#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int dp[1005][1005];
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mp[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[1][1] = 1;
				continue;
			}
			if (mp[i][j] == '#') continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= (int)(1e9 + 7);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}