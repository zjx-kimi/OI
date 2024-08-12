#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9;
const int M = 4e2 + 9;
int ans[M][N];
int n, arr[N], q, p, k, nn;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n; nn = sqrt (n);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int K = 1; K <= nn; K++) { // 枚举 k
  	for (int i = n; i >= 1; i--) {
  	  if (i + arr[i] + K > n) ans[K][i] = 1;
	  else ans[K][i] = ans[K][i + arr[i] + K] + 1;
  	}
  }
  cin >> q;
  while (q--) {
  	cin >> p >> k;
  	if (k <= nn) {
  		cout << ans[k][p] << '\n';
  	} else {
  		int cnt = 0;
  		while (p <= n) 
  			p += k + arr[p], cnt++;
  		cout << cnt << '\n';
  	}
  }
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}