#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int dp[N];
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 2; i <= n; i++) {
		dp[i] = INT_MAX;
		for (int j = 1; j <= min(i - 1,k); j++){
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n] << endl;
}