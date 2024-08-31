/*
a % b = a - k * b 其中 k = a / b
如果知道 b, k，那么 a 属于 [kb, kb + b - 1] 
因为要求 (a % b)_max 所以 a 也要求 max
O (n log n)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 2e6;
int n;
int f[M + 5];
int a[N], ans = -1;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    int maxn = a[n];
    for (int i = 1; i <= n; i++) f[a[i]] = a[i];
    for (int i = 1; i <= M; i++)
        f[i] = max(f[i - 1], f[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) { // 枚举的 b = a[i]
        for (int j = 1; j * a[i] - 1 <= maxn; j++) { // 枚举的 k
            int now = j * a[i] + a[i] - 1;
            if (f[now] > a[i])
                ans = max(ans, f[now] % a[i]);
        }
    }
    printf("%d", ans);
}