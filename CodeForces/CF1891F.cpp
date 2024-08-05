#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 5e5 + 10;
struct SegTree {
  struct Node {
    int l, r, sum, lazy;
  } tr[N << 2];
  void pushup(int u) { tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; }
  void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.lazy) {
      left.sum += root.lazy * (left.r - left.l + 1),
          right.sum += root.lazy * (right.r - right.l + 1);
      left.lazy += root.lazy, right.lazy += root.lazy;
      root.lazy = 0;
    }
  }
  void build(int u, int l, int r) {
    tr[u] = {l, r, 0, 0};
    if (l >= r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
  void modify(int u, int l, int r, int val) {
    if (l <= tr[u].l && r >= tr[u].r) {
      tr[u].sum += val * (tr[u].r - tr[u].l + 1);
      tr[u].lazy += val;
      return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, val);
    if (r > mid) modify(u << 1 | 1, l, r, val);
    pushup(u);
  }
  int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
      return tr[u].sum;
    }
    int res = 0, mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
  }
} seg;
vector<int> e[N];
int n, m, k;
int tot, idx;
int dfn[N], sz[N], res[N], vis[N];
struct Query {
  int op, v, val, son;
} q[N];
void clear() {
  for (int i = 1; i <= tot; i++) {
    e[i].clear();
    sz[i] = 0;
    vis[i] = 0;
  }
  idx = 0;
}
void dfs(int u) {
  dfn[u] = ++idx, sz[u] = 1;
  for (auto v : e[u]) {
    dfs(v), sz[u] += sz[v];
  }
}
void solve() {
  tot = 1;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> q[i].op;
    if (q[i].op == 1) {
      cin >> q[i].v;
      e[q[i].v].push_back(++tot);
      q[i].son = tot;
    } else
      cin >> q[i].v >> q[i].val;
  }
  dfs(1);
  seg.build(1, 1, tot);
  for (int i = m; i >= 1; i--) {
    if (q[i].op == 1) {
      vis[q[i].son] = 1;
      res[q[i].son] = seg.query(1, dfn[q[i].son], dfn[q[i].son]);
    } else {
      seg.modify(1, dfn[q[i].v], dfn[q[i].v] + sz[q[i].v] - 1, q[i].val);
    }
  }

  for (int i = 1; i <= tot; i++) {
    if (!vis[i]) {
      res[i] = seg.query(1, dfn[i], dfn[i]);
    }
    cout << res[i] << " \n"[i == tot];
  }
  clear();
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}