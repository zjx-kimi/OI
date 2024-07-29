#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9;
const int M = 20;
int n, m, x, y, z;
int dep[N], fa[N][M]; 
vector <int> edge[N]; 
void dfs (int x, int Father) {
	fa[x][0] = Father;
	dep[x] = dep[Father] + 1;
	for (int i = 1; i < 15; i++) 
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for (int i : edge[x]) {
		if (i != x) {
			dfs (i, x);
		}
	}
	return;
}
int lca (int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 14; i >= 0; i--) {
		if (dep[fa[a][i]] >= dep[b]) {
			a = fa[a][i];
		}
	}
	if (a == b) return a;
	for (int i = 14; i >= 0; i--) {
		if (fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}

void updata (int &o, int l, int r, int )
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
  	cin >> x >> y;
  	edge[x].push_back(y);
  	edge[y].push_back(x);
  }
  dfs(1, 0);
  while (m--) {
  	cin >> x >> y >> z;

  }
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}