#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, x, y, q, f[N];
int root[N], tot;
int ls[N], rs[N], id[N], sum[N];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void pushup(int u) { sum[u] = sum[ls[u]] + sum[rs[u]]; }
int change(int u, int l, int r, int p, int i) {
    if (!u) u = ++tot;
    if (l == r) {
        id[u] = i;
        sum[u]++;
        return u;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
        ls[u] = change(ls[u], l, mid, p, i);
    else
        rs[u] = change(rs[u], mid + 1, r, p, i);
    pushup(u);
    return u;
}
int merge(int x, int y) {
    if (!x || !y) return x + y;
    ls[x] = merge(ls[x], ls[y]);
    rs[x] = merge(rs[x], rs[y]);
    pushup(x);
    return x;
}
int query(int u, int l, int r, int k) {
    if (l == r) return id[u];
    int ans = 0;
    int mid = (l + r) >> 1;
    if (k <= sum[ls[u]])
        ans = query(ls[u], l, mid, k);
    else
        ans = query(rs[u], mid + 1, r, k - sum[ls[u]]);
    return ans;
}
int main() {
	cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        cin >> x;
        root[i] = change(root[i], 1, n, x, i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if (x == y) continue;
        f[y] = x;
        root[x] = merge(root[x], root[y]);
    }
    cin >> q;
    while (q--) {
    	char c;
    	cin >> c;
        if (c == 'B') {
        	cin >> x >> y;
            x = find(x),             y = find(y);
            if (x == y) continue;
            f[y] = x;
            root[x] = merge(root[x], root[y]);
        } else {
        	cin >> x >> y;
            x = find(x);
            int ans = query(root[x], 1, n, y);
            ans = ans ? ans : -1;
            printf("%d\n", ans);
        }
    }
}