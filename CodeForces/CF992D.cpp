#include<bits/stdc++.h>
using namespace std;
const long long maxv = 2e18;
const int maxn = 2e5 + 10;
long long a[maxn], pre[maxn];
int suc[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; long long k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        if (a[i + 1] != 1) suc[i] = i + 1;
        else suc[i] = suc[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long mul = 1, sum = 0;
        for (int j = i; j <= n; j++) {
            if (a[j] > maxv / mul) break;
            mul *= a[j];
            sum = k * (pre[j] - pre[i - 1]);
            if (mul == sum) ans++;
            if (a[j] == 1 && sum < mul && mul % k == 0) {
                ans += (sum + (suc[j] - j - 1) * k >= mul);
            }
            if (a[j] == 1) j = suc[j] - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}