#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 30;
const int Mod = 1e9 + 7;
int n;
bool a[maxn][maxn];
int dp[maxn][1<<22];
int dfs(int x, int s) {
	if (dp[x][s] != -1) return dp[x][s];
	if(x == n + 1) {
		dp[x][s] = 1;
		return 1;
	}
	dp[x][s] = 0;
	for (int i = 1; i <= n; i++) {
		if(a[x][i] && !(s & (1 << (i - 1)))) {
			dp[x][s] += dfs(x + 1, s + (1 << (i - 1)));
			dp[x][s] %= Mod;
		}
	}
	return dp[x][s];
}
signed main(){
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
	cout << dfs(1, 0);
	return 0;
}