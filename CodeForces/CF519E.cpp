#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int LG = 20;
vector<int> edge[N];
int siz[N], depth[N], fa[N][LG];
int n, m, x, y;

void dfs(int node, int f) {
    siz[node] = 1;
    depth[node] = depth[f] + 1;
    fa[node][0] = f;

    for (int i = 1; i < LG; ++i) {
        fa[node][i] = fa[fa[node][i - 1]][i - 1];
    }

    for (int neighbor : edge[node]) {
        if (neighbor == f) continue;
        dfs(neighbor, node);
        siz[node] += siz[neighbor];
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    for (int i = LG - 1; i >= 0; --i) {
        if (depth[x] - (1 << i) >= depth[y]) {
            x = fa[x][i];
        }
    }
    if (x == y) return x;
    for (int i = LG - 1; i >= 0; --i) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
void getans(int x, int y) {
    if (x == y) {
        printf("%d\n", siz[1]);
        return;
    }
    if (depth[x] == depth[y]) {
        for (int i = 14; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
        }
        printf("%d\n", siz[1] - siz[x] - siz[y]);
        return;
    }
    if (depth[x] < depth[y]) swap(x, y);
    if ((depth[x] - depth[y]) & 1) return puts("0"), void();
    int dist = (depth[x] + depth[y] - 2 * depth[lca(x, y)]) / 2 - 1;
    for (int i = 15; i >= 0; i--) {
        if (dist & (1 << i)) x = fa[x][i];
    }
    printf("%d\n", siz[fa[x][0]] - siz[x]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    scanf("%d", &m);

    while (m--) {
        scanf("%d %d", &x, &y);
        getans(x, y);
    }

    return 0;
}