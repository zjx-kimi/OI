#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int dp[N];
int a[N], b[N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for (int i = 1; i <= n * 1000; i++) dp[i] =  0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		for (int j = n * 1000; j >= b[i]; j--) {
			dp[j] = min(dp[j], dp[j - b[i]] + a[i]);
		}
	}
	for (int i = n * 1000; i > 0; i--) {
		if (dp[i] <= m) {
			cout << i << endl;
			return 0;
		}
	}
}