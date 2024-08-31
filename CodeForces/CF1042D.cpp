#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
long long val[200005];
int cnt[200005];
int n, m;
long long ans;
long long pref;
long long t, a[200005];
long long num[200005];
int id[200005];
int sz[MAXN << 2];
map<long long, int> times;

void update(int o) { sz[o] = sz[o << 1] + sz[o << 1 | 1]; }
void build(int o, int l, int r) {
    if (l == r) {
        sz[o] = cnt[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    update(o);
}
int query(int o, int l, int r, int k) {
    if (!k) return 0;
    if (r <= k) {
        return sz[o];
    }
    int mid = (l + r) >> 1, sum = 0;
    sum += query(o << 1, l, mid, k);
    if (k > mid) sum += query(o << 1 | 1, mid + 1, r, k);
    return sum;
}

void remove(int o, int l, int r, int k) {
    if (l == r) {
        sz[o]--;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) remove(o << 1, l, mid, k);
    else remove(o << 1 | 1, mid + 1, r, k);
    update(o);
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        a[i] = a[i - 1] + num[i];
        times[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    m = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 0; i < m; i++) {
        val[i + 1] = a[i + 1];
        cnt[i + 1] = times[a[i + 1]];
    }
    build(1, 1, m);
    for (int i = 0; i < n; i++) {
        pref += num[i];
        int k = lower_bound(val + 1, val + m + 1, pref + t - 1) - val;
        if (k > m) k = m;
        if (val[k] >= pref + t) k--;
        if (k) ans += (long long)query(1, 1, m, k);
        int p = lower_bound(val + 1, val + m + 1, pref + num[i + 1]) - val;
        remove(1, 1, m, p);
    }
    cout << ans << endl;
}
