#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9;
bool vis[N];
int n, x;
int arr[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n + 10; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	vis[arr[1]] = true;
	for (int i = 2; i <= n; i++) {
		x = arr[i];
		if (vis[x - 1] == 0 && vis[x + 1] == 0) 
			return puts("NO"), void();
		vis[x] = 1;
	}
	return puts("YES"), void();
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
    int t = 1;
    cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}