// Problem: D - K-th Nearest
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_d
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n, q, aa, k;
vector <int> a;
int countLessThanOrEqualToX(int x) {
    auto it = upper_bound(a.begin(), a.end(), x);
    return it - a.begin();
}
int countGreaterThanOrEqualToX(int x) {
    auto it = lower_bound(a.begin(), a.end(), x);
    return a.end() - it;
}
int check (int x) {
	int count = countLessThanOrEqualToX(aa - x) + countGreaterThanOrEqualToX(aa + x);
	if (count >= n - k + 1) return -1;
	if (count < n - k + 1) return 1;
}
signed main() {
	cin >> n >> q;
	a.resize(n);
	for (int &i : a) cin >> i;
	sort(a.begin(), a.end());
	
	// for (int &i : a) cout << i << ' '; cout << '\n';
	while (q--) {
		cin >> aa >> k;
		int l = 0, r = INT_MAX / 4, ans;
		while (l <= r) {
			int mid = (l + r) / 2;
			int res = check(mid);
			// cout << mid << ' ' << res << '\n';
			if (res == -1) {
				l = mid + 1;
				ans = mid;
			} else if (res == 1) {
				r = mid - 1;
			}
		}
		cout << ans << '\n';
	}
}