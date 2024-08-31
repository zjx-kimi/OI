#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005;
const int M = 105;
int n, k;
int a[N], b[N];
int calc (int a, int b, int k) {
    if (a > b) swap (a, b);
    if (k <= a * a) 
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}