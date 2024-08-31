#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9;
int n, m, k;
int x[N], y[N], du[N], vis[N];
map <pair <int, int>, bool> ex;
vector <int> edge[N];
queue <int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
    	cin >> x[i] >> y[i];
    	ex[{x[i], y[i]}] = true;
    	ex[{y[i], x[i]}] = true;
    	du[x[i]]++ ,du[y[i]]++;
    	edge[x[i]].push_back(y[i]);
    	edge[y[i]].push_back(x[i]);
    }
    for (int i = 1; i <= n; i++) if (du[i] < k) q.push(i);
    while (q.size()) {
    	int top = q.front(); q.pop();
    	for (int i : edge[top]) {
    		if (ex[{top, i}] && !vis[i]) {
    			
    		}
    	}
    }
    return 0;
}