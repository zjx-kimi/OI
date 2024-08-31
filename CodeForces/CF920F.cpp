#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 300100;
int tree[N], a[N];
int fa[N], m, n, q, l, r, t;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void add(int x, int y) {
    while (x <= n) {
        tree[x] += y;
        x += (x & -x);
    }
}
int qry(int x) {
    int r = 0;
    while (x) {
        r += tree[x];
        x -= (x & -x);
    }
    return r;
}
int fun(int x) {
    int res = 1;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        res *= cnt + 1;
    }
    if (x != 1) res *= 2;
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], add(i, a[i]), fa[i] = i;
    fa[n + 1] = n + 1;
    while (m--) {
        cin >> q >> l >> r;
        if (l > r) swap(l, r);
        if (q == 2)
            cout << qry(r) - qry(l - 1) << '\n';
        else
            for (int i = l; i <= r;) {
                int t = (int)fun(a[i]);
                add(i, t - a[i]);
                fa[i] = (a[i] == t) ? i + 1 : i;
                a[i] = t;
                i = (find(i) == i) ? i + 1 : fa[i];
            }
    }
}