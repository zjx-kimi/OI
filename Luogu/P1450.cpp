#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
int dp[N];
int c[5], d[5], n, sum;
signed main() {
    cin >> c[1] >> c[2] >> c[3] >> c[4] >> n;
    dp[0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = c[i]; j <= 100000; j++) dp[j] += dp[j - c[i]];
    while (n--) {
        int res = 0;
        cin >> d[1] >> d[2] >> d[3] >> d[4] >> sum;
        for (int i = 0; i < 16; i++) {
            int t = sum;
            int o = 1;
            for (int j = 1; j <= 4; j++)
                if ((i >> (j - 1)) & 1)
                    t -= c[j] * (d[j] + 1), o *= -1;
            if (t < 0) continue;
            res += o * dp[t];
        }
        cout << res << endl;
    }
    return 0;
}