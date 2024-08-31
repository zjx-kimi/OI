#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005], b[200005];
int t, y;
signed main() {
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int f = 0;
        int x = a * b;
        for (int i = a + 1; i <= c; i++) {
            int y = x / __gcd(x, i);
            y = d / y * y;
            if (y > b) {
                cout << i << ' ' << y << endl;
                f = 1;
                break;
            }
        }
        if (!f) cout << "-1 -1\n";
    }
}
