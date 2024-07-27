#include<bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
    int n, k; 
    cin >> n >> k;
    if (n == k) cout << "YES\n1\n1\n";
    else if (k * 2 <= n) cout << "YES\n2\n" << n - k + 1 << " 1\n";
    else if ((n & 1) && 2 * k - 1 == n) cout << "YES\n2\n2 1\n";
    else cout << "NO\n";
    return;
}

signed main() {
    ios:: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}