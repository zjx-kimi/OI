#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 80 * N;
int n, m, u, v, x, y, z;
vector<int> edge[N]; // 使用 vector 存储图的边
int f[N][21], dep[N];
int sum[M], maxz[M], ls[M], rs[M];
int ans[N], root[N], cnt;
inline void add(int x, int y) {
    edge[x].push_back(y);
    edge[y].push_back(x);
}

void dfs(int x, int fa) {
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    for (int i = 1; i <= 17; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int y : edge[x]) {
        if (y == fa) continue;
        dfs(y, x);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 16; i >= 0; i--)
        if (dep[f[a][i]] >= dep[b])
            a = f[a][i];
    if (a == b) return a;
    for (int i = 16; i >= 0; i--)
        if (f[a][i] != f[b][i]) {
            a = f[a][i];
            b = f[b][i];
        }
    return f[a][0];
}

void pushup(int rt) {
    if (sum[ls[rt]] >= sum[rs[rt]])
        sum[rt] = sum[ls[rt]], maxz[rt] = maxz[ls[rt]];
    else
        sum[rt] = sum[rs[rt]], maxz[rt] = maxz[rs[rt]];
}

void update(int &rt, int l, int r, int z, int val) {
    if (!rt) rt = ++cnt;
    if (l == r) {
        sum[rt] += val;
        maxz[rt] = z;
        return;
    }
    int mid = (l + r) >> 1;
    if (z <= mid) update(ls[rt], l, mid, z, val);
    else update(rs[rt], mid + 1, r, z, val);
    pushup(rt);
}

int merge(int u, int v, int l, int r) {
    if (!u || !v) return u + v;
    if (l == r) {
        sum[u] += sum[v];
        return u;
    }
    int mid = (l + r) >> 1;
    ls[u] = merge(ls[u], ls[v], l, mid);
    rs[u] = merge(rs[u], rs[v], mid + 1, r);
    pushup(u);
    return u;
}

void calc(int x, int fa) {
    for (int y : edge[x]) {
        if (y == fa) continue;
        calc(y, x);
        root[x] = merge(root[x], root[y], 1, 1e5);
    }
    ans[x] = maxz[root[x]];
    if (!sum[root[x]]) ans[x] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        add(u, v);
    }
    dfs(1, 0);
    while (m--) {
        cin >> x >> y >> z;
        int k = lca(x, y);
        update(root[x], 1, 1e5, z, 1);
        update(root[y], 1, 1e5, z, 1);
        update(root[k], 1, 1e5, z, -1);
        update(root[f[k][0]], 1, 1e5, z, -1);
    }
    calc(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}