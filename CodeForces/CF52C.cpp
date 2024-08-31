#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
struct node {
    int val, l, r, Min, lazy;
} t[4 * N];
int a[N], n, m;
void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    t[p].lazy = 0;
    if (l == r) {
        t[p].val = a[l];
        t[p].Min = a[l]; 
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    t[p].val = t[p * 2].val + t[p * 2 + 1].val;
    t[p].Min = min(t[p * 2].Min, t[p * 2 + 1].Min);
}
void pushdown(int p) {
    t[p * 2].val += (t[p * 2].r - t[p * 2].l + 1) * t[p].lazy;
    t[p * 2].Min += t[p].lazy;
    t[p * 2].lazy += t[p].lazy;
    t[p * 2 + 1].val += (t[p * 2 + 1].r - t[p * 2 + 1].l + 1) * t[p].lazy;
    t[p * 2 + 1].Min += t[p].lazy;
    t[p * 2 + 1].lazy += t[p].lazy;
    t[p].lazy = 0;
}
void change(int p, int x, int y, int k) {
    if (t[p].l >= x && t[p].r <= y) {
        t[p].val += (t[p].r - t[p].l + 1) * k;
        t[p].Min += k;
        t[p].lazy += k;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid) change(p * 2, x, y, k);
    if (mid < y) change(p * 2 + 1, x, y, k);
    t[p].val = t[p * 2].val + t[p * 2 + 1].val;
    t[p].Min = min(t[p * 2].Min, t[p * 2 + 1].Min);
}
int query(int p, int x, int y) {
    if (t[p].l >= x && t[p].r <= y) return t[p].Min;
    pushdown(p);
    int ans = 1e16, mid = (t[p].l + t[p].r) / 2;
    if (x <= mid) ans = min(ans, query(p * 2, x, y));
    if (mid < y) ans = min(ans, query(p * 2 + 1, x, y));
    return ans;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, k;
        char c;
        scanf ("%lld %lld%c", &l, &r, &c);
        ++l; ++r;
        if (c == ' ') {
            cin >> k;
            if (l <= r) 
                change(1, l, r, k);
            else { 
                change(1, l, n, k); 
                change(1, 1, r, k);
            }
        } else {
            if (l <= r) 
                cout << query(1, l, r) << endl;
            else 
                cout << min(query(1, l, n), query(1, 1, r)) << endl;
        }
    }
    return 0;
}
