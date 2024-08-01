#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
double p[N];
int n;
double dp[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	dp[0] = 1.0;
	for (int i = 1; i <= n; i++) {
		for (int j = i ; j >= 1; j--) {
			if (j)
				dp[j] = dp[j] * (1 - p[i]) + dp[j - 1] * p[i];
			else
				dp[j] = dp[j] * (1 - p[i]);
		}
		dp[0] = dp[0] * (1 - p[i]);
	}
	double ans = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[i];
	}
	printf("%.10lf",ans);
}