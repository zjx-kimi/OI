#include <bits/stdc++.h>
using namespace std;
const int N = 3000005;
int n;
vector<int> ver[N];
int ans[N];
int a[N], hs[N], fa[N];
int lc[N], rc[N], tot = 0;
int v[N], l[N], r[N];
int root[N];
void push_up(int p) {
    v[p] = v[lc[p]] + v[rc[p]];
}
void build(int& p, int le, int ri, int x) {
    p = ++tot;
    l[p] = le;
    r[p] = ri;
    if (le == ri) {
        v[p] = 1;
        return;
    }
    int mid = (le + ri) >> 1;
    if (x <= mid)
        build(lc[p], le, mid, x);
    else
        build(rc[p], mid + 1, ri, x);
    push_up(p);
}
void add(int p, int x) {
    if (l[p] == r[p]) {
        v[p]++;
        return;
    }
    int mid = (l[p] + r[p]) >> 1;
    if (x <= mid)
        add(lc[p], x);
    else
        add(rc[p], x);
    push_up(p);
}
int merge(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    if (l[x] == r[x]) return v[x] += v[y], x;
    lc[x] = merge(lc[x], lc[y]);
    rc[x] = merge(rc[x], rc[y]);
    push_up(x);
    return x;
}
int query(int p, int le, int ri) {
    if (p == 0) return 0;
    if (l[p] == le && r[p] == ri) return v[p];
    int mid = (l[p] + r[p]) >> 1;
    if (le <= mid) {
        if (ri > mid) return query(lc[p], le, mid) + query(rc[p], mid + 1, ri);
        return query(lc[p], le, ri);
    }
    return query(rc[p], le, ri);
}
void dfs(int x) {
    for (int i = ver[x].size() - 1; i >= 0; i--) {
        dfs(ver[x][i]);
        root[x] = merge(root[x], root[ver[x][i]]);
    }
    ans[x] = query(root[x], a[x] + 1, n + 1);
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        hs[i] = a[i];
    }
    sort(hs + 1, hs + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(hs + 1, hs + n + 1, a[i]) - hs;
        build(root[i], 1, n + 1, a[i]);
    }
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        ver[fa[i]].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
