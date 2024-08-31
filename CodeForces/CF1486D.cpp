#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], b[N], sum[N], n, len;
bool check(int p) {
    for (int i = 1; i <= n; i++) sum[i] = (a[i] >= p ? 1 : -1) + sum[i - 1];
    for (int minn = 0, i = len; i <= n; i++) {
        minn = min(minn, sum[i - len]);
        if (sum[i] > minn) return true;
    }
    return false;
}
int main() {
    scanf("%d %d", &n, &len);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int R = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + R, a[i]) - b;
    int l = 1, r = R, ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    printf("%d", b[ans]);
    return 0;
}