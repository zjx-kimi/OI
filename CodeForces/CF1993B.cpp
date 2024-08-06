#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
#ifdef kimi
	assert(freopen(".in", "r", stdin));
	assert(freopen(".out", "w", stdout));
#endif
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		int s = -1;
		vector<int> v;
		for (int x : a) {
			if (x % 2 == 0) v.push_back(x);
			else if (x > s) s = x;
		}
		sort(v.begin(), v.end());

		if (s == -1 || v.empty()) {
			cout << 0 << endl;
			continue;
		}

		int ans = v.size();
		for (int t : v) {
			if (t < s) s += t;
			else {
				ans += 1;
				break;
			}
		}

		cout << ans << endl;
	}
	return 0;
}