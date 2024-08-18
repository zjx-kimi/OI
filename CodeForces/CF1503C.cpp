#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 100005;
int n, ans, nowh;
struct node {
    int h, val, pos;
} a[maxn];
bool cmp(node x, node y) { return x.val < y.val; }
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val >> a[i].h;
        ans += a[i].h;
        a[i].h += a[i].val;
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1, cmp); 
    nowh = a[1].h;
    for (int i = 1; i <= n; i++) {
        int val = a[i].val;
        if (val > nowh) ans += val - nowh;
        nowh = max(nowh, a[i].h);
    }
    cout << ans << '\n';
    return 0;
}