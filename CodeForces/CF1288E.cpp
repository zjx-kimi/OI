#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
#define ll long long
using namespace std;
const int N = 6e5 + 10;
int n, m;
int a[N], minn[N], maxx[N], pos[N];
int arr[N];
int tree[N];
void updata (int i, int x) {
	while (i <= n + m) {
		tree[i] += x;
		i += lowbit(i);
	}
}
int query (int x) {
	int ans = 0;
	while (x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
  	minn[i] = maxx[i] = i;
  	pos[i] = m + i;
  	updata(pos[i], 1);
  }
  for (int i = m + 1; i <= m + n; i++) arr[i] = i - m;
  for (int i = 1; i <= m; i++) {
  	minn[a[i]] = 1;
  	maxx[a[i]] = max(maxx[a[i]], query(pos[a[i]]));
  	updata(pos[a[i]], -1);
  	pos[a[i]] = m - i + 1;
  	updata(pos[a[i]], 1);
  }
  for (int i = 1; i <= n; i++) {
  	maxx[i] = max(maxx[i], query(pos[i]));
  }
  for (int i = 1; i <= n; i++) {
  	cout << minn[i] << ' ' << maxx[i] << '\n';
  }
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}