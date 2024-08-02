#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, Len[N], Cnt, L, R, mid, res;
char s[N];
inline bool check(const int& x) {
    int tot = 0;
    for (int i = 0; i <= Cnt; ++i) {
        if (Len[i] > x) { tot += Len[i] / (x + 1); }
    }
    return tot <= k;
}
int main() {
	cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        if ((s[i] == 'N') ^ (i & 1)) res++;
        if (i > 0 && s[i] != s[i - 1]) Len[++Cnt] = 1;
        else Len[Cnt]++;
    }
    if (res <= k || n - res <= k) return puts("1"), 0;
    L = 2, R = n;
    while (L <= R) {
        mid = (L + R) >> 1;
        if (check(mid)) {
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << L << '\n';
    return 0;
}