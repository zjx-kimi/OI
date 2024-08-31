#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")

using namespace std;

const int N = 15e6 + 5;

int p, cnt, v[N], tag[N], ls[N], rs[N];

void pushup(int u) {
	v[u] = v[ls[u]] + v[rs[u]];
}

void pushdown(int u, int len) {
	if (tag[u] == -1) return;
	if (!ls[u]) ls[u] = ++cnt;
	if (!rs[u]) rs[u] = ++cnt;
	tag[ls[u]] = tag[rs[u]] = tag[u];
	v[ls[u]] = ((len + 1) >> 1) * tag[u];
	v[rs[u]] = (len >> 1) * tag[u];
	tag[u] = -1;
}

void update(int &u, int l, int r, int L, int R, int k) {
	if (!u) u = ++cnt;
	if (L <= l && r <= R) {
		v[u] = k * (r - l + 1);
		tag[u] = k;
		return;
	}
	pushdown(u, r - l + 1);
	int mid = (l + r) >> 1;
	if (L <= mid) {
		update(ls[u], l, mid, L, R, k);
	}
	if (R > mid) {
		update(rs[u], mid + 1, r, L, R, k);
	}
	pushup(u);
}

int n, Q;

signed main() {
	memset(tag, -1, sizeof tag);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> Q;
	update(p, 1, n, 1, n, 1);
	while (Q--) {
		int op, l, r;
		cin >> l >> r >> op;
		op--;
		update(p, 1, n, l, r, op);
		cout << v[1] << '\n';
	}
	return 0;
}