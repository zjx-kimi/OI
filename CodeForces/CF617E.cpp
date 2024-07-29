#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7 + 9;
const int M = 1e5 + 9;
int n, m, k, siz, l, r;
int arr[M], pos[M], cnt[N];
int ans[M];  // 使用 ll 类型以避免溢出
int now = 0; // 初始化 now
struct Q {
    int l, r, k;
} q[M];

bool cmp(Q x, Q y) {
    if (pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
    return x.r < y.r;
}

void add(int x) {
    now += cnt[arr[x] ^ k];
    cnt[arr[x]]++;
}

void sub(int x) {
    cnt[arr[x]]--;
    now -= cnt[arr[x] ^ k];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    siz = sqrt(n);
    
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
        pos[i] = i / siz;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].k = i;
    }
    
    sort(q, q + m, cmp);
    
    l = 0; // 初始化 l
    r = -1; // 初始化 r
    for (int i = 0; i < m; i++) {
        while (q[i].l < l) add(--l);
        while (q[i].r > r) add(++r);
        while (q[i].l > l) sub(l++);
        while (q[i].r < r) sub(r--);
        ans[q[i].k] = now;
    }
    
    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
    cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
    
    return 0;
}
