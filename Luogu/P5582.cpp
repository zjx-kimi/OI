#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
bool s[MAXN];
int main() {
#ifdef kimi
	assert(freopen(".in", "r", stdin));
	assert(freopen(".out", "w", stdout));
#endif
	int n, m, d, a, ans = 0;
	cin >> n >> m >> d;
	int gc = __gcd(n, d);
	for (int i = 1; i <= m; i++) {
		cin >> a;
		s[a % gc] = 1;
	}
	for (int i = 0; i < gc; i++)
		if (!s[i])
			ans += (n / gc);
	printf("%d", ans);
	return 0;
}