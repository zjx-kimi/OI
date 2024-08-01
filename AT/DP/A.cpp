#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N];
int dp[N];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	dp[2] = abs(h[2] - h[1]);
	for (int i = 3; i <= n; i++) dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),dp[i - 2] + abs(h[i - 2] - h[i]));
	cout << dp[n] << endl;
}