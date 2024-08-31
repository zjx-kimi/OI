#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5001;
int n, x[N], fa[N], ans[N], num[N];
int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y) { fa[find(x)] = find(y); }
signed main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n; i++)  fa[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (x[i] * x[j] > 0)	{
				int tmp = (int)sqrt(x[i] * x[j]);
				if (tmp * tmp == x[i] * x[j])
					merge(i, j);
			}
	for (int i = 1; i <= n; i++)	{
		int tot = 0;
		memset(num, 0, sizeof(num));
		for (int j = i; j <= n; j++)
			if (x[j] == 0)
				ans[max(1ll, tot)]++;
			else {
				if (!num[find(j)])
					num[find(j)] = 1, tot++;
				ans[tot]++;
			}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}