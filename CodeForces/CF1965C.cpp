#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;
int n, L, R, pos, fx;
string s;
void solve() {
	cin >> n >> s;
	s = " " + s;
	L = 1e9, R = -1e9, pos = 0, fx = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == s[i - 1]) fx *= -1;
		else pos += fx;
		L = min(L, pos),
		R = max(R, pos);
	}
	cout << R - L + 1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
  	solve();
  }
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}