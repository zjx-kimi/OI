#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, M = 1e3;
int vis[N + 10], x;
int main() {
#ifdef kimi
	assert(freopen("in.txt", "r", stdin));
	assert(freopen("out.txt", "w", stdout));
#endif
	for (int i = 1; i <= N; i++) vis[i] = -1;
	cin >> x;
	vis[x] = 0;
	for (int i = 1; i <= M; i++) {
		cout << "+ " << 1 << endl;
		cin >> x;
		if (vis[x] != -1) {
			cout << "! " << i - vis[x] << endl;
			return 0;
		}
		vis[x] = i;
	}
	for (int i = 1; ; i++) {
		cout << "+ " << M << endl;
		cin >> x;
		if (vis[x] != -1) {
			cout << "! " << M * (i + 1) - vis[x] << endl;
			return 0;
		}
	}
	return 0;
}