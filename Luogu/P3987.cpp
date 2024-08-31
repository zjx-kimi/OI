#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char IN[1 << 17], *SS = IN, *TT = IN;

inline char gc() { return (SS == TT && (TT = (SS = IN) + fread(IN, 1, 1 << 17, stdin), SS == TT) ? EOF : *SS++); }
inline int read() {
    int now = 0, f = 1;
    register char c = gc();
    for (; !isdigit(c); c == '-' && (f = -1), c = gc());
    for (; isdigit(c); now = now * 10 + c - '0', c = gc());
    return now * f;
}

const int maxn = 100003;
const int maxk = 500003;
int n, Q, A[maxn];
vector<int> T[maxk];
vector<int>::iterator pos1, pos2, it;
vector<vector<int>::iterator> be_to_del;

namespace BLT {
    ll tr[maxn];

    inline int lowbit(int x) { return x & (-x); }
    
    inline void add(int x, int k) {
        while (x <= n) {
            tr[x] += k;
            x += lowbit(x);
        }
    }

    inline ll sum(int x, ll s = 0) {
        while (x) {
            s += tr[x];
            x -= lowbit(x);
        }
        return s;
    }

    inline ll query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
}

using namespace BLT;

inline void work(int pos, int x) {
    for (register int i = 1; i <= sqrt(x); i++) {
        if (x % i) continue;
        T[i].push_back(pos);
        if (x / i != i) T[x / i].push_back(pos);
    }
}

inline void Clean() {
    vector<vector<int>::iterator> tmp;
    swap(tmp, be_to_del);
}

inline void change(int l, int r, int k) {
    if (k == 1 || T[k].empty()) return;
    
    pos1 = lower_bound(T[k].begin(), T[k].end(), l);
    pos2 = upper_bound(T[k].begin(), T[k].end(), r);
    Clean();
    
    for (it = pos1; it != pos2; ++it) {
        if (A[*it] % k) continue;
        add(*it, -(A[*it] - A[*it] / k)), A[*it] /= k;
        if (A[*it] % k) be_to_del.push_back(it);
    }
    
    if (be_to_del.empty()) return;
    for (register int i = be_to_del.size() - 1; i >= 0; i--) {
        T[k].erase(be_to_del[i]);
    }
}

int main() {
    n = read(), Q = read();
    for (register int i = 1; i <= n; i++) {
        A[i] = read();
        add(i, A[i]);
        work(i, A[i]);
    }
    
    while (Q--) {
        int flag = read();
        if (flag == 1) {
            int x = read(), y = read(), k = read();
            change(x, y, k);
        } else if (flag == 2) {
            int x = read(), y = read();
            printf("%lld\n", query(x, y));
        }
    }
    
    return 0;
}