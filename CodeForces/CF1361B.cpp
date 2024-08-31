#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 9;
const int mod = 1e9 + 7;
int n, p, mx, mn, flag, x;
map <int, int> m;
inline int qpow (int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    int res = qpow(x, y / 2);
    if (y & 1) return res * res % mod * x % mod;
    return res * res % mod;
}
void solve() {
    cin >> n >> p;
    m.clear(); mx = 0, mn = 0, flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        m[-x]++; // 从大到小
    }
    if (p == 1) return cout << (n & 1) << endl, void();
    for (auto i : m) {
        int k = -i.first;
        int cnt = i.second;
        int val = qpow(p, k);
        if (flag) {
            (mn += val * cnt % mod) %= mod;
            continue;
        }
        if (cnt & 1) {
            int need = 1;
            for (int j = k - 1; j >= 0; j--) {
                need *= p;
                if (need > n) break;
                if (!m.count(-j)) continue;
                need -= m[-j];
                if (need <= 0) {
                    need = 0;
                    break;
                }
            }
            if (!need) {
                need = 1;
                for (int j = k - 1; j >= 0; j--) {
                    need *= p;
                    if (need > n) break;
                    if (!m.count(-j)) continue;
                    int tmp = min(m[-j], need);
                    need -= tmp;
                    m[-j] -= tmp;
                    if (need <= 0) {
                        need = 0;
                        break;
                    }
                }
            } else {
                flag = 1;
                (mx += val) %= mod;
            }
        }

    }
    cout << (mx - mn + mod) % mod << endl;
}
signed main() {
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