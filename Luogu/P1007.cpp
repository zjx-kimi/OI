#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long n, l, p, maxv = 0, minv = 0, b = 1;
	cin >> l >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> p;
		if (0 < p && p <= l) b = 0;
		maxv = max(maxv, max(l - p + 1, p));
		minv = max(minv, min(l - p + 1, p));
	}
	if (b == 1) cout << 0 << " " << 0;
	else cout << minv << " " << maxv;
	return 0;
}