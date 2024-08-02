#include <bits/stdc++.h>
using namespace std;
int dp1[100010], dp2[100010], mod;
int pro1[100010], pro2[100010];
vector<int> edge[100010];
void dfs1(int u, int fa) {
    dp1[u] = 1;
    vector<int> edgeson;
    for (int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if (v == fa) continue;
        dfs1(v, u);
        dp1[u] = 1LL * dp1[u] * (dp1[v] + 1) % mod;
        edgeson.push_back(v); 
    }
    int pre1 = 1;
    int pre2 = 1;
    for (int i = 0; i < edgeson.size(); i++) {
        pro1[edgeson[i]] = pre1;
        pre1 = 1LL * pre1 * (dp1[edgeson[i]] + 1) % mod;
    } 
    for (int i = edgeson.size() - 1; i >= 0; i--) {
        pro2[edgeson[i]] = pre2;
        pre2 = 1LL * pre2 * (dp1[edgeson[i]] + 1) % mod;
    } 
}
void dfs2(int u, int fa) {
    if (fa == -1)
        dp2[u] = 1;
    else
        dp2[u] = (1LL * dp2[fa] * (1LL * pro1[u] * pro2[u] % mod) % mod + 1) % mod;
    for (int i = 0; i < edge[u].size(); i++) {
        if (edge[u][i] == fa) continue;
        dfs2(edge[u][i], u);
    }
}
int main() {
    int n;
    scanf("%d%d", &n, &mod);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) printf("%d\n", 1LL * dp1[i] * dp2[i] % mod);
    return 0;
}