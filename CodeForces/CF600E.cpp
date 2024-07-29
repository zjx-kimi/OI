#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1e5 + 10;

struct node {
	int ls, rs, maxn;
	ll ans;
};

int n, m;
int c[MAXN];

int cnt;
int fa[MAXN];
int rt[MAXN];

node tr[MAXN * 100];

vector <int> edge[MAXN];

void find (int x, int f) {
	fa[x] = f;
	for (int i = 0; i < edge[x].size(); ++i) {
		int to = edge[x][i];
		if (to == f) {
			continue;
		}
		find(to, x);
	}
}

void push_up (int id) {
	int ls = tr[id].ls;
	int rs = tr[id].rs;
	if (tr[ls].maxn > tr[rs].maxn) {
		tr[id].maxn = tr[ls].maxn;
		tr[id].ans = tr[ls].ans;
	} else if (tr[ls].maxn == tr[rs].maxn) {
		tr[id].maxn = tr[ls].maxn;
		tr[id].ans = tr[ls].ans + tr[rs].ans;
	} else {
		tr[id].maxn = tr[rs].maxn;
		tr[id].ans = tr[rs].ans;
	}
}

int merge (int a, int b, int l, int r) {
	if (!a || !b) {
		return a += b;
	}
	int id = ++cnt;
	if (l == r) {
		tr[id].maxn = tr[a].maxn + tr[b].maxn;
		tr[id].ans = tr[a].ans;
		return id;
	}
	int mid = l + r >> 1;
	tr[id].ls = merge(tr[a].ls, tr[b].ls, l, mid);
	tr[id].rs = merge(tr[a].rs, tr[b].rs, mid + 1, r);
	push_up(id);
	return id;
}

void update (int &id, int L, int val, int l, int r) {
	if (!id) {
		id = ++cnt;
	}
	if (l == r && l == L) {
		tr[id].maxn += val;
		tr[id].ans = L;
		return;
	}
	int mid = l + r >> 1;
	if (L <= mid) {
		update(tr[id].ls, L, val, l, mid);
	} else {
		update(tr[id].rs, L, val, mid + 1, r);
	}
	push_up(id);
}

void dfs (int x, int fa) {
	for (int i = 0; i < edge[x].size(); ++i) {
		int to = edge[x][i];
		if (to == fa) {
			continue;
		}
		dfs(to, x);
		rt[x] = merge(rt[x], rt[to], 1, 1e5);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	edge[0].push_back(1);
	edge[1].push_back(0);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	find(0, 0);
	for (int i = 1; i <= n; ++i) {
		update(rt[i], c[i], 1, 1, 1e5);
	}
	dfs(0, 0);
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", tr[rt[i]].ans);
	}
	return 0;
}