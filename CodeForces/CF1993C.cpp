

#include <bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5;

int n, k, d[2 * N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		int mx = -1;
		fill(d, d + 2 * k, 0);

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			assert(x >= 1);
			d[x % (2 * k)]++;
			mx = max(mx, x);
		}

		int cnt = 0;
		int ans = INT_MAX;
		for (int i = 0; i <= k - 2; i++) {
			cnt += d[i];
		}

		for (int l = 0, r = k - 1; l < 2 * k; l++, r++) {
			if (r >= 2 * k) r -= 2 * k;

			if (cnt += d[r]; cnt == n) {
				int wait = (r - mx) % (2 * k);
				if (wait < 0) wait += 2 * k;
				ans = min(ans, mx + wait);
			}

			cnt -= d[l];
		}

		if (ans == INT_MAX) {
			ans = -1;
		}
		cout << ans << '\n';
	}
}