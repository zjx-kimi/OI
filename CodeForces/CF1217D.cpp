#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
struct Edge {
    int u, v;
} e[N];
int n, m, In[N], cnt;
vector<int> G[N];
bool TopSort() {
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (!In[i]) q.push(i);
    while (q.size()) {
        int u = q.front(); q.pop();
        ++cnt;
        for (int v : G[u])
            if (--In[v] == 0) q.push(v);
    }
    return cnt == n;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ++In[v];
        e[i] = { u, v };
        G[u].push_back(v);
    }
    if (TopSort()) {
        cout << 1 << '\n';
        for (int i = 1; i <= m; i++) cout << "1 ";
    } else {
        cout << 2 << '\n';
        for (int i = 1; i <= m; i++) cout << (e[i].u < e[i].v ? 1 : 2) << ' ';
    }
    return 0;
}