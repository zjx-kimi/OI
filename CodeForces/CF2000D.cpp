#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;
ll n, arr[N], l, r, ans, sum[N];
string s;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
    cin >> s; s = " " + s;
    l = 1, r = n, ans = 0;
    while (l <= r) {
        while (l <= r && s[l] == 'R') l++;
        while (r >= l && s[r] == 'L') r--;
        if (l > r) return cout << ans << '\n', void();
        ans += sum[r] - sum[l - 1];
        l++, r--;
    }
    cout << ans << '\n';
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}