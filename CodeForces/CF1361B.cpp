#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;
const int mod = 1e9 + 7;
int n, p, mx, mn, flag, x;
map <int, int> m;
void solve() {
    cin >> n >> p;
    m.clear(); mx = 0, mn = 0, flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        m[-x]++; // 从大到小
    }
    if (p == 1) return cout << (n & 1) <<
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