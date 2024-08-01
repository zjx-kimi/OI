#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
ll a[N], f[N][N], pre[N];
int n;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) f[i][j] = 1ll << 60;
        f[i][i] = 0;
    }
    for (int i = n; i >= 1; i--) { 
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + pre[j] - pre[i - 1]);
            }
        }
    }
    cout << f[1][n];
    return 0;
}