#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 10;
const int Mod = 1e9 + 7;
bool vis[N];
int n;
int dp[N][2];
vector<int> edge[N];
void dfs(int x) {
	vis[x] = 1;
	dp[x][1] = 1;
	dp[x][0] = 1;
	for (int i = 0; i < edge[x].size(); i++) {
		if(!vis[edge[x][i]]) {
			dfs(edge[x][i]);
			dp[x][1] *= dp[edge[x][i]][0] + dp[edge[x][i]][1];
			dp[x][1] %= Mod;
			dp[x][0] *= dp[edge[x][i]][1];
			dp[x][0] %= Mod;
		}
	}
} 
signed main(){
	cin >> n;
	if(n == 1) {
		cout << 2;
		return 0;
	} 
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(1);
//	for (int i = 1; i <= n; i++) cout << dp[i][0] << ' '; cout << endl;
//	for (int i = 1; i <= n; i++) cout << dp[i][1] << ' '; cout << endl;
	cout << (dp[1][0] + dp[1][1]) % Mod;
	return 0;
}