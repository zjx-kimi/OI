// Problem: D. Water Tree
// Contest: Codeforces - Codeforces Round 200 (Div. 1)
// URL: https://codeforces.com/problemset/problem/343/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, Q, x, y, op;
int tim, dfn[N], siz[N], fa[N]; // 时间戳; dfs 序; 子树大小; 父亲节点
int sum[N * 4], lazy[N * 4]; // 和; 懒标记 
vector <int> edge[N];
void dfs(int x, int f) {
	fa[x] = f, dfn[x] = ++tim, siz[x] = 1;
	for (int i : edge[x]) {
		if (i != f) {
			dfs(i, x);
			siz[x] += siz[i];
		}
	}
	return; 
}
void pushdown(int o, int l, int r) {
	if (lazy[o] == -1) return;
	lazy[o * 2] = lazy[o * 2 + 1] = lazy[o];
	int mid = (l + r) >> 1;
	sum[o * 2] = lazy[o] * (mid - l + 1);
	sum[o * 2 + 1] = lazy[o] * (r - mid);
	return; 
}
void pushup(int o) {
	sum[o] = sum[o * 2] + sum[o * 2 + 1];
}
int query (int o, int l, int r, int L, int R) { // id; nL; nR; qL; qR
	if (L <= l && r <= R) return sum[o];
	pushdown(o, l, r);
	int result = 0, mid = (l + r) >> 1;
	if (L <= mid) result += query(o * 2, l, mid, L, R);
	if (R >= mid + 1) result += query(o * 2, l, mid, L, R);
	return result;
}
void updata (int o, int l, int r, int L, int R, int Tag) {
	if (L <= l && r <= R) {
		sum [o]= (r - l + 1) * Tag;
		lazy[o] = Tag;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) updata(o * 2, l, mid, L, R, Tag);
	if (R >= mid + 1) updata(o * 2 + 1, mid + 1, r, L, R, Tag);
	pushup(o);
}
bool check (int x) { // 判断 x 的子树有没有 0
	return query (1, 1, n, dfn[x], dfn[x] + siz[x] - 1) < siz[x];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n * 4; i++) lazy[i] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs (1, 0);
	cin >> Q;
	while (Q--) {
		cin >> op >> x;
		if (op == 1) {
			if (x != 1 && check(x)) 
				updata(1, 1, n, dfn[fa[x]], dfn[fa[x]], 0);
			updata(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, 1);
		} else if (op == 2) {
			updata (1, 1, n, dfn[x], dfn[x], 0);
		} else {
			cout << !check(x) << '\n';
		}
	}
}
/*


- 给出一棵以 $1$ 为根节点的 $n$ 个节点的有根树。每个点有一个权值，初始为 $0$。
- $m$ 次操作。操作有 $3$ 种：
    1. 将点 $u$ 和其子树上的所有节点的权值改为 $1$。
    2. 将点 $u$ 到 $1$ 的路径上的所有节点的权值改为 $0$。
    3. 询问点 $u$ 的权值。
- $1\le n,m\le 5\times 10^5$。


考虑使用线段树
*/