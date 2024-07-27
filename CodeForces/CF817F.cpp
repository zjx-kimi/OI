#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define low lower_bound
const int maxn = 15 + 10;
ll book[maxn << 2], dpl[maxn], dpr[maxn];
int sum[maxn << 4], tag[maxn << 4], opt[maxn];

inline void pushup(int p) {
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

inline void addtag(int p, int pl, int pr, int k) {
    if (k == 1) {
        sum[p] = (pr - pl + 1) * 1;
        tag[p] = 1;
    } else if (k == 2) {
        sum[p] = (pr - pl + 1) * 0;
        tag[p] = 2;
    } else if (k == 3) {
        if (tag[p] == 0) {
            sum[p] = pr - pl + 1 - sum[p];
            tag[p] = 3;
        } else if (tag[p] == 1) {
            sum[p] = (pr - pl + 1) * 0;
            tag[p] = 2;
        } else if (tag[p] == 2) {
            sum[p] = (pr - pl + 1) * 1;
            tag[p] = 1;
        } else if (tag[p] == 3) {
            sum[p] = pr - pl + 1 - sum[p];
            tag[p] = 0;
        }
    }
}

inline void pushdown(int p, int pl, int pr) {
    if (tag[p] == 0) return;
    int mid = (pl + pr) >> 1;
    addtag(p << 1, pl, mid, tag[p]);
    addtag(p << 1 | 1, mid + 1, pr, tag[p]);
    tag[p] = 0;
}

inline void update(int l, int r, int p, int pl, int pr, int opt) {
    if (l <= pl && pr <= r) {
        addtag(p, pl, pr, opt);
        return;
    }
    int mid = (pl + pr) >> 1;
    pushdown(p, pl, pr);
    if (l <= mid) update(l, r, p << 1, pl, mid, opt);
    if (r > mid) update(l, r, p << 1 | 1, mid + 1, pr, opt);
    pushup(p);
}

inline int query(int p, int pl, int pr) {
    if (pl == pr) return pl;
    int mid = (pl + pr) >> 1;
    pushdown(p, pl, pr);
    if (sum[p << 1] < mid - pl + 1)
        return query(p << 1, pl, mid);
    else
        return query(p << 1 | 1, mid + 1, pr);
}

int main() {
    int m;
    scanf("%d", &m);
    int pos = 0;
    book[++pos] = 1;

    for (int i = 1; i <= m; i++) {
        scanf("%d", &opt[i]);
        scanf("%lld%lld", &dpl[i], &dpr[i]);
        book[++pos] = dpl[i];
        book[++pos] = dpr[i];
        book[++pos] = dpr[i] + 1;
    }

    sort(book + 1, book + 1 + pos);
    int cnt = unique(book + 1, book + 1 + pos) - book - 1;

    for (int i = 1; i <= m; i++) {
        dpl[i] = low(book + 1, book + 1 + cnt, dpl[i]) - book;
        dpr[i] = low(book + 1, book + 1 + cnt, dpr[i]) - book;
        update(dpl[i], dpr[i], 1, 1, cnt, opt[i]);
        printf("%lld\n", book[query(1, 1, cnt)]);
    }

    return 0;
}
