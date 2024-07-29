#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100100;
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
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], add(i, a[i]), fa[i] = i;
    cin >> m;
    fa[n + 1] = n + 1;
    while (m--) {
        cin >> q >> l >> r;
        if (l > r) swap(l, r);
        if (q == 1)
            cout << qry(r) - qry(l - 1) << '\n';
        else
            for (int i = l; i <= r;) {
                int t = (int)sqrt(a[i]);
                add(i, t - a[i]);
                a[i] = t;
                fa[i] = (a[i] <= 1) ? i + 1 : i;
                i = (find(i) == i) ? i + 1 : fa[i];
            }
    }
}