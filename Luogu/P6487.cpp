#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int f[110], n, ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n;
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= 100; i++) f[i] = f[i - 1] + f[i - 2];
    for (int i = 0; i <= 100; i++) if (f[i] == n) {
    	cout << n << '\n';
    	return 0;
    }
    ans = n;
    for (int i = 0; i <= 100; i++) if (n > f[i]) ans = min(ans, n - f[i]);
    
    cout << ans << '\n';
    return 0;
}