#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, a, b, c, x, y, max_dep, ans;
int dep[N], vis[N];
vector<int> edge[N];
queue<int> q;
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    if (dep[x] > max_dep) a = x, max_dep = dep[x];
    for (int i : edge[x]) {
        if (i != fa) {
            dfs(i, x);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    b = a, max_dep = 0;
    dfs(b, 0);
    for (int i = a; i != b;) {
        q.push(i), vis[i] = 1;
        for (int j : edge[i]) {
            if (dep[j] == dep[i] - 1) {
                i = j;
                break;
            }
        }
    }
    q.push(b);
    vis[b] = 1;
    for (int i = 1; i <= n; i++) dep[i] = 0;
    while (q.size()) {
        int top = q.front();
        q.pop();
        for (int i : edge[top])
            if (!vis[i]) {
                dep[i] = dep[top] + 1;
                if (dep[i] > ans) {
                    c = i, ans = dep[i];
                }
                ans = max(ans, dep[i]);
                vis[i] = true;
                q.push(i);
            }
    }
    cout << ans + max_dep - 1 << '\n';
    if (c == 0) 
    	for (int i = 1; i <= n; i++) 
		    if (i != a && i != b) {
		    	c = i;
		    	break;
		    }
    cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}