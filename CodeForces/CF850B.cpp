#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 9;
int n, x, y, Ans = 2e17;
int arr[N], cnt[N], sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cnt[arr[i]]++, sum[arr[i]] += arr[i];
    for (int i = 1; i <= N - 9; i++) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
    if (cnt[1] == n) return cout << min(x, y) * n << '\n', 0;
    for (int i = 2; i <= (1e6); i++) {
	    int ans = 0;
	    for (int j = i; j <= (1e6) + i; j += i) {
	        int r = j;
	        int l = r - i + 1;
	        int upd = r - (int)(ceil((double)x / (double)y) + 0.5);
	        if (upd >= l)
	            ans += x * (cnt[upd] - cnt[l - 1]);
	        else
	            upd = l - 1;
	        ans += y * ((cnt[r] - cnt[upd]) * r - (sum[r] - sum[upd]));
	    }
	    Ans = min(Ans, ans);
	}
    cout << Ans << '\n';
    return 0;
}