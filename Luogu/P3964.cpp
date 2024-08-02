#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5;
int n, sumx, sumy; 
int x[N + 5], y[N + 5], p[N + 5], q[N + 5];
int ans = LLONG_MAX, prex[N + 5], prey[N + 5];

signed main() {
    cin >> n;
    for (int a, b, i = 1; i <= n; ++i) {
        cin >> a >> b;
        x[i] = p[i] = a + b, y[i] = q[i] = a - b;
    }
    sort(p + 1, p + n + 1);
    sort(q + 1, q + n + 1);
    for (int a, b, i = 1; i <= n; ++i)
        prex[i] = prex[i - 1] + p[i], prey[i] = prey[i - 1] + q[i];
    for (int posx, posy, i = 1; i <= n; ++i) {
        posx = lower_bound(p + 1, p + n + 1, x[i]) - p;
        posy = lower_bound(q + 1, q + n + 1, y[i]) - q;
        sumx = posx * x[i] - prex[posx] + prex[n] - prex[posx] - (n - posx) * x[i];
        sumy = posy * y[i] - prey[posy] + prey[n] - prey[posy] - (n - posy) * y[i];
        ans = min(ans, sumx + sumy);
    }
    cout << ans / 2 << '\n';
    return 0;
}