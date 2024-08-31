#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
	if (x > 0) cout << "+ " << x << endl;
	else cout << "- " << -x << endl;
	cin >> x;
	return x;
}

const int maxn = 1010;

int n = 339, a[maxn], b[maxn];
mt19937 rnd(time(NULL));

int main() {
	int k = 0;
	cin >> k;
	for (int _ = 0; _ < 998 - n * 2; ++_) {
		a[0] = ask(rnd() % 1000000000 + 1);
		k = max(k, a[0]);
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = ask(1);
	}
	b[0] = ask(k);
	for (int i = 1; i <= n; ++i) {
		b[i] = ask(n);
	}
	int ans = 1e9;
	for (int i = 0; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[i] == a[j]) {
				ans = min(ans, j - i);
			}
			if (b[i] == b[j]) {
				ans = min(ans, (j - i) * n);
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (a[i] == b[j]) {
				ans = min(ans, n - i + j * n + k);
			}
		}
	}
	cout << "! " << ans << endl;
}