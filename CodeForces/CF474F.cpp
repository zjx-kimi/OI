#include <bits/stdc++.h>
#define fi first
#define se second
#define multi false
#define gc getchar
#define pc putchar
#define pb push_back
#define int long long
#define pii pair<int, int>
#define debug(x) cout << #x << " " << x << '\n'

#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define Rof(i, x, y) for (int i = (x); i >= (y); i--)

using namespace std;

inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }

int read(char ch = ' ', int x = 0, int w = 1) {
    while (!isdigit(ch)) {
        if (ch == '-') w = -1;
        ch = gc();
    }
    while (isdigit(ch)) { x = x * 10 + (ch - '0'), ch = gc(); }
    return x * w;
}
void read(int& x) { x = read(); }
void read(int n, int a[]) { For(i, 1, n) a[i] = read(); }
void read(int n, int a[], int b[]) { For(i, 1, n) a[i] = read(), b[i] = read(); }

void write(int x) {
    if (x < 0) x = -x, pc('-');
    if (x > 9) write(x / 10);
    pc(x % 10 + '0');
}
void write(int n, int a[]) { For(i, 1, n) write(a[i]), pc(' '); }
/*=============================================================================================================================================================================================*/
const int N = 1e5 + 10;

int t = 1, n, q, l, r;
int Gcd[N * 4], arr[N], Cnt[N * 4];

#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((l + r) >> 1)

void pushup(int o) {
    Gcd[o] = gcd(Gcd[ls], Gcd[rs]);
    Cnt[o] = (Gcd[ls] == Gcd[o]) * Cnt[ls] + (Gcd[rs] == Gcd[o]) * Cnt[rs];
    return;
}

void build(int o, int l, int r) {
    if (l == r) {
        Gcd[o] = arr[l];
        Cnt[o] = 1;
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(o);
}

int getGcd(int o, int l, int r, int L, int R) {
    if (l >= L && r <= R)
        return Gcd[o];
    if (R <= mid)
        return getGcd(o * 2, l, mid, L, R);
    else if (L > mid)
        return getGcd(o * 2 + 1, mid + 1, r, L, R);
    else
        return gcd(getGcd(o * 2, l, mid, L, R), getGcd(o * 2 + 1, mid + 1, r, L, R));
}
int query(int o, int l, int r, int L, int R, int t) {
    if (l >= L && r <= R)
        return (Gcd[o] == t) * Cnt[o];
    if (R <= (l + r) / 2)
        return query(o * 2, l, mid, L, R, t);
    else if (L > (l + r) / 2)
        return query(o * 2 + 1, mid + 1, r, L, R, t);
    else
        return query(o * 2, l, mid, L, R, t) + query(o * 2 + 1, mid + 1, r, L, R, t);
}
#undef ls
#undef rs
#undef mid

void solve() {
    read(n), read(n, arr);
    build(1, 1, n);
    read(q);
    
    while (q--) {
        cin >> l >> r;
        cout << r - l - query(1, 1, n, l, r, getGcd(1, 1, n, l, r)) + 1 << endl;
    }
}
signed main() {
    if (multi) read(t);
    while (t--) solve();
    cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}