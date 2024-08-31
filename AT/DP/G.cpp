#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 1e5 + 10;
vector<int>Edge[N];
int n, m;
int dp[N];
int du[N];
bool vis[N];
int dfs(int x) {
	if(dp[x]) return dp[x];
	for (int i = 0; i < Edge[x].size(); i++) {
		dp[x] = max(dp[x], dfs(Edge[x][i]) + 1);
	}
	return dp[x];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		Edge[x].push_back(y); 
	}
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		ans = max(dfs(i), ans);
	}
	cout << ans << endl;
} 