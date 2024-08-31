#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;
    vector <int> va, vb;
    for (int i = 1; i * i <= a; i++) if (a % i == 0) va.push_back(i), va.push_back(a / i);
    for (int i = 1; i * i <= b; i++) if (b % i == 0) vb.push_back(i), vb.push_back(b / i);
    for (int i : va) for (int j : vb) {
        int x = i * j;
        int y = a * b / x;
        x = (a / x + 1) * x;
        y = (b / y + 1) * y;
        if (a < x && x <= c && b < y && y <= d) return cout << x << ' ' << y << '\n', void();
    }
    return cout << "-1 -1\n", void();
}
signed main () {
    cin >> t;
    while (t--) solve();
}

/*
10
1 1 2 2
3 4 5 7
8 9 15 18
12 21 14 24
36 60 48 66
1024 729 373248 730
1024 729 373247 730
5040 40320 40319 1000000000
999999999 999999999 1000000000 1000000000
268435456 268435456 1000000000 1000000000


2 2
4 6
12 12
-1 -1
-1 -1
373248 730
-1 -1
15120 53760
-1 -1
536870912 536870912
*/
