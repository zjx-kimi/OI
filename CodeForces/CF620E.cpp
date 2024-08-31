#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5 + 9;
const int M = N << 2;
int n, m, cnt, x, y;
vector <int> Edge[N]; // 边
int arr[N], Arr[N], id[N], siz[N]; // siz 包括其本身
ll L[M], R[M], tag[M], val[M];
void dfs (int x, int fa) {
	id[x] = ++cnt, siz[id[x]] = 1;
	for (int i : Edge[x]) {
		if (i == fa) continue;
		dfs (i, x);
		siz[id[x]] += siz[id[i]];
	}
	return;
}
void build (int o, int l, int r) {
	L[o] = l, R[o] = r;
	if (l == r) {
		val[o] = (1 << Arr[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build (o * 2, l, mid); build (o * 2 + 1, mid + 1, r);
	val[o] = val[o * 2] | val[o * 2 + 1];
	return;
} 
void updata (int o, int l, int r) {
	if (l <=)
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
    	cin >> x >> y;
    	Edge[x].push_back(y);
    	Edge[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) Arr[id[i]] = arr[i];
    dfs (1, 0); build(1, 1, n);

    return 0;
}