#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(2e5 + 10);
int n, c;
int h[N];
int q[N];
int dp[N];
inline double X(int i) {
	return h[i];
}
inline double Y(int i) {
	return (dp[i] + (h[i] * h[i]));
}
inline double K(int i, int j) {
	return ((Y(j) - Y(i)) / (X(j) - X(i)));
}
signed main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> h[i];
	int head = 1, tail = 1;
	q[1] = 1 + (dp[1] = 0);
	for (int i = 2; i <= n; i++) {
		while (head < tail && (h[i] << 1) >= K(q[head], q[head + 1]))++head;
		dp[i] = dp[q[head]] + (h[q[head]] - h[i]) * (h[q[head]] - h[i]) + c;
		while (head < tail && K(i, q[tail]) <= K(q[tail], q[tail - 1]))--tail;
		q[++tail] = i;
	}
	cout << dp[n];
	return 0;
}