#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m, dis, cnt;
int f[N][30], ans[N][30], dep[N];
int fa[N];
struct edge {
    int v, w, u;
} e[N], E[N];
bool cmp(edge a, edge b) { return a.w < b.w; }
int find(int a) { return fa[a] == a ? a : fa[a] = find(fa[a]); }
vector<pair<int, int>> edge[N];
void kruskal() {
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        if (find(e[i].u) == find(e[i].v)) continue;
        fa[find(e[i].v)] = find(e[i].u);
        cnt++;
        edge[e[i].v].push_back({ e[i].u, e[i].w });
        edge[e[i].u].push_back({ e[i].v, e[i].w });
        dis += e[i].w;
        if (cnt == n - 1) return;
    }
    return;
}
void dfs(int x, int fa, int len) {
    dep[x] = dep[fa] + 1;
    f[x][0] = fa, ans[x][0] = len;
    for (int i = 1; i <= 20; i++) {
        f[x][i] = f[f[x][i - 1]][i - 1];
        ans[x][i] = max(ans[x][i - 1], ans[f[x][i - 1]][i - 1]);
    }
    for (pair<int, int> i : edge[x]) {
        if (i.first == fa) continue;
        dfs(i.first, x, i.second);
    }
}
int lca(int a, int b) {
    int maxx = 0;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 20; i >= 0; i--) {
        if (dep[a] <= dep[f[b][i]]) {
            maxx = max(maxx, ans[b][i]);
            b = f[b][i];
        }
    }
    if (a == b) return maxx;
    for (int i = 20; i >= 0; i--) {
        if (f[a][i] == f[b][i]) continue;
        maxx = max(ans[b][i], max(maxx, ans[a][i]));
        b = f[b][i], a = f[a][i];
    }
    return max(maxx, max(ans[a][0], ans[b][0]));
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
        e[i] = E[i];
    }
    kruskal();
    dfs(1, 0, 0);
    for (int i = 1; i <= m; i++)
        cout << dis + E[i].w - lca(E[i].u, E[i].v) << '\n';
    return 0;
}