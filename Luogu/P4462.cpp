#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 5;
int n, m, k;
int a[N], pos[N], cnt[N];
int ans[N];
int now;
struct Q {
    int l, r, k;
} q[N];
void Add(int n) {
    cnt[a[n]]++;
    now += cnt[a[n]] * cnt[a[n]] - (cnt[a[n]] - 1) * (cnt[a[n]] - 1);
}
void Sub(int n) {
    cnt[a[n]]--;
    now -= (cnt[a[n]] + 1) * (cnt[a[n]] + 1) - cnt[a[n]] * cnt[a[n]];
}
bool cmp (Q x, Q y) { return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l]; }
signed main() {
    cin >> n >> m >> k;
    int siz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        pos[i] = i / siz;
    }

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].k = i;
    }

    sort(q, q + m, cmp);

    int l = 1, r = 0;
    for (int i = 0; i < m; i++) {
        while (q[i].l < l) Add(--l);
        while (q[i].r > r) Add(++r);
        while (q[i].l > l) Sub(l++);
        while (q[i].r < r) Sub(r--);
        ans[q[i].k] = now;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << ' ';
    return 0;
}
