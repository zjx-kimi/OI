#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, k;
long long sum[10];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    long long ans = 0;
    for (int i = 0; i < m; ++i) sum[i] = -1e18;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < m; ++j) sum[j] += x;
        sum[i % m] = max(sum[i % m], 1ll * x) - k;
        for (int j = 0; j < m; ++j) ans = max(ans, sum[j]);
    }
    printf("%lld\n", ans);
    return 0;
}