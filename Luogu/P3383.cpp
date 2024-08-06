#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
bitset <N + 10> num;
vector <int> p;
int n, q;

void init() {
	for (int i = 2; i <= N; i++) {
		if (!num[i]) {
			p.push_back(i);
		}
		for (int j : p) {
			if (i * j > N) break;
			num[i * j] = true;
			if (i % j == 0) break;
		}
	} 
}

int main() {
#ifdef kimi
	assert(freopen("in.txt", "r", stdin));
	assert(freopen("out.txt", "w", stdout));
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> n >> q;

	while (q--) {
		int x;
		cin >> x;
		cout << p[x - 1] << '\n';
	}
	return 0;
}