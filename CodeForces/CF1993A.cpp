#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() {
	cin >> n >> s;
	int a = count(s.begin(), s.end(), 'A');
	int b = count(s.begin(), s.end(), 'B');
	int c = count(s.begin(), s.end(), 'C');
	int d = count(s.begin(), s.end(), 'D');
	cout << min(a, n) + min(b, n) + min(c, n) + min(d, n) << endl;
}
int main() {
#ifdef kimi
	assert(freopen(".in", "r", stdin));
	assert(freopen(".out", "w", stdout));
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}