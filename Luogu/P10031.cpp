#include <bits/stdc++.h>
#define int long long
using namespace std;
int q, n;
signed main() {
#ifdef kimi
	assert(freopen("in.txt", "r", stdin));
	assert(freopen("out.txt", "w", stdout));
#endif
	cin >> q;
	while (q--) {
		cin >> n;
		if (n & 1) cout << n << '\n';
		else cout << ((n / 2) ^ n) << '\n';
	}
	return 0;
}