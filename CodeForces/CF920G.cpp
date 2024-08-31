#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;
int t;
int x, p, k, cnt, sum, mid, res = 1;
map <int, int> mp;
vector <pair <int, int>> ve;
void dfs (int x) {
	if (x == ve.size()) {
		cnt -= (sum & 1 ? 1 : -1) * (mid / res - (x + res - 1) / res + 1);
		return;
	}
	int tmp = res;
	dfs (x + 1);
	for (int i = 1; i <= ve[x].second; i++) {
		res *= ve[x].first;
		sum++;
		dfs (x + 1);
	}
	res = tmp, sum -= ve[x].second;
}
bool check (int mid) {
	cnt = mid - x + 1, sum = 0, res = 1;
	dfs (0);
	return cnt <= k;
}
void init (int p) {
	mp.clear(); ve.clear();
	for (int i = 2; i * i <= p; i++) 
		while (p % i == 0) 
			mp[i]++, p /= i;

	return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> t;
    while (t--) {
    	cin >> x >> p >> k;
    	init(p);
    	int l = x + 1, r = 1e9, ans = -1;
    	while (l <= r) {
    		mid = (l + r) >> 1;
    		if (check(mid)) {
    			r = mid - 1;
    			ans = mid;
    		} else {
    			l = mid + 1;
    		}
    	}
    	cout << ans << '\n';

    }
    return 0;
}