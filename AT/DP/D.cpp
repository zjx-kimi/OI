#include<bits/stdc++.h>
using namespace std;
long long v[105];
long long w[105];
long long dp[100005];
int main() {
	int n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (long long i = 1; i <= n; i++) { // 枚举物品数
		for (long long j = m; j >= 0; j--) { // 枚举空间
			if(j >= w[i])
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m];
}