#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define fi first
#define se second
#define multi true
#define gc getchar
#define pc putchar
#define pb push_back
#define int long long
#define pii pair <int, int>
#define debug(x) cout << #x << " = " << x << '\n'
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define Rof(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
const int N = 1e7 + 9;
const int mod = 1e9+ 7;
const int Mod = 998244353;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a * b / gcd(a, b);}
int read(char ch = ' ', int x = 0, int w = 1) { while (!isdigit(ch)) { if (ch == '-') w = -1; ch = gc(); } while (isdigit(ch)) { x = x * 10 + (ch - '0'), ch = gc(); } return x * w; }
void read(int &x) { x = read(); }
void read(int n, int a[]) {For (i, 1, n) a[i] = read();}
void read(int n, int a[], int b[]) {For (i, 1, n) a[i] = read(), b[i] = read();}
void write(int x) { if (x < 0) x = -x, pc('-'); if (x > 9) write(x / 10); pc(x % 10 + '0'); }
void write(int n, int a[]) {For (i, 1, n) write(a[i]), pc(' '); }
/*=============================================================================================================================================================================================*/
int t = 1, n, m, k;
void solve() {
	cin >> n >> m >> k;
	cout << min(n, k) * min(m, k) << '\n';
  return;
}
signed main() { 
  #ifdef kimi
    freopen("in.txt", "r", stdin); 
    freopen("out.txt", "w", stdout);
  #endif
  if (multi) read(t); 
  while (t--) solve();
  return 0;
}
