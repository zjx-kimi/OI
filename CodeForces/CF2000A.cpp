#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;

void solve() {
	string s;
	cin >> s;
	if (s.size() < 3) return puts("NO"), void();
	if (s[0] == '1' && s[1] == '0' && s[2] != '0') {
		s = s.substr(2);
		int S = stoi(s);
		if (S >= 2) return puts("YES"), void();
	}
	puts("NO");
	return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}