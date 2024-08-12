#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, a[N + 5], tag1[N + 5], tag2[N + 5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], tag1[i] = tag2[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (!a[i]) continue;
            if (tag1[i] && a[i] <= 2) continue;
            if (tag1[i] && tag2[i] && a[i] <= 4) continue;
            if (a[i] <= 2)
                tag1[i] = tag1[i + 1] = 1;
            else if (a[i] <= 4)
                if (tag2[i])
                    tag1[i] = tag1[i + 1] = 1;
                else if (tag1[i])
                    tag2[i] = tag2[i + 1] = 1;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
