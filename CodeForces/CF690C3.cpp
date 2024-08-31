#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 9;
int n, dep[maxn], f[maxn][24], S, T, d, fa;
int lca (int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 23; ~i; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
	if (u == v) return u;
	for (int i = 23; ~i; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
	return f[u][0];
}

inline int dis (int u, int v) {
	return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
	cin >> n;
	S = T = 1, d = 0;
	for (int u = 2; u <= n; u++) {
		cin >> fa;
		dep[u] = dep[fa] + 1, f[u][0] = fa;
		for (int i = 1; (1 << i) <= dep[u]; i++) f[u][i] = f[f[u][i - 1]][i - 1];
		if (fa == S) S = u, d++;
		else if (fa == T) T = u, d++;
		else {
			int dis1 = dis(u, T), dis2 = dis(u, S);
			if (dis1 > d) d = dis1, S = u;
			if (dis2 > d) d = dis2, T = u;
		}
		cout << d << ' ';
	}
}