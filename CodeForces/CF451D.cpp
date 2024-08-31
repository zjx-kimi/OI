#include <bits/stdc++.h>
using namespace std;

int len, t;
long long ans[2];
long long sum[2][2];
string s;

int main() {
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; ++i) {
		ans[1]++;
		t = s[i] - 'a';
		if (i & 1) {
			ans[0] += sum[0][t];
			ans[1] += sum[1][t];
		}
		else {
			ans[0] += sum[1][t];
			ans[1] += sum[0][t];
		}
		++sum[i & 1][t];
	}
	cout << ans[0] << " " << ans[1] << "\n";
    cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
	return 0;
}