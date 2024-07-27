#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int k, f[105][105][26], s[105][105], ans;
string t;

signed main() {
    cin >> n >> k >> t, t = " " + t;
    for (int i = 1; i <= n; i++) {
        f[i][1][t[i] - 'a'] = 1;
        for (int j = 1; j <= i; j++) {
            for (int c = 0; c < 26; c++) {
                if (c + 'a' == t[i])
                    f[i][j][c] += s[i - 1][j - 1];
                else
                    f[i][j][c] += f[i - 1][j][c];
                if (f[i][j][c] > k)
                    f[i][j][c] = k;
                
                s[i][j] += f[i][j][c];
            }

            if (s[i][j] > k)
                s[i][j] = k;
        }
    }
    
    s[n][0] = 1;

    for (int i = n; i >= 0; i--) {
        if (s[n][i] > k) {
            ans += k * (n - i);
            k = 0;
            break;
        }
        
        ans += s[n][i] * (n - i);
        k -= s[n][i];
    }

    if (k) return puts("-1"), 0;
    cout << ans;
    return 0;
}
