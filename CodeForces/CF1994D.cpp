// 鸽巢原理，抽屉原理
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2005;
int t, n;
int a[N], b[N];
vector < pair <int, int> > ans;
set <int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		s.clear(); ans.clear();
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) s.insert(i);
		for (int i = n - 1; i >= 1; i--) { // 枚举每一个模数 (x)
			for (int j = 0; j < i; j++) b[j] = 0; // 清空
			for (int j : s) {
				if (b[a[j] % i]) {
					ans.push_back({j,  b[a[j] % i]});
					s.erase(j);
					break;
				} else {
					b[a[j] % i] = j;
				}
			}
		}
		cout << "YES\n";
		for (int i = n - 2; i >= 0; i--) cout << ans[i].first << " " << ans[i].second << '\n';

	}
  	cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  	return 0;
}