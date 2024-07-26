#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;
    vector <int> va, vb;
    for (int i = 1; i * i <= a; i++) if (a % i == 0) va.push_back(i), va.push_back(i);
    for (int i = 1; i * i <= c; i++) if (c % i == 0) vb.push_back(i), vb.push_back(c / i);
    for (int i : va) for (int j : vb) {
        int k = i * j;
        int x = (a / k + 1) / k;
    }
}
int main () {
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
