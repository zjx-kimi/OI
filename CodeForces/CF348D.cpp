#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 9;
const int M = 3005;
const int mod = 1e9 + 7;
int n, m;
string s[M];
int f[M][M];
int dp(int a, int b, int c, int d) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = 0;
  	for (int i = a; i <= c; i++)
  		for (int j = b; j <= d; j++)
  			if (s[i][j] == '#') f[i][j] = 0;
			else if (i == a && j == b) f[i][j] = 1;
			else f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
	return f[c][d];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
  	cin >> s[i];
  	s[i] = " " + s[i];
  }
  cout << ( dp(1, 2, n - 1, m) * dp(2, 1, n, m - 1) % mod - dp(1, 2, n, m - 1) * dp(2, 1, n - 1, m) % mod + mod ) % mod;
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}