#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int inf = (1LL << 31) - 1;
const int llf = 2e18;
const int mod = 1e9 + 7;

int T;
int m[N], l[N], r[N], sc[N], n, sm, slen, sl, sr;

struct node {
    int w, k;
};

vector<node> p[N];
unordered_map<int, int> P;
unordered_map<int, int> Q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n;
        sm = slen = sl = sr = 0;
        for (int i = 1; i <= n; i++) {
            p[i].clear();
            cin >> m[i] >> l[i] >> r[i];
            sc[i] = 0;
            sm += m[i];
            slen += r[i] - l[i];
            sl += l[i];
            sr += r[i];
            for (int j = 1; j <= m[i]; j++) {
                int x;
                cin >> x;
                p[i].push_back({ x, 0 });
            }
            for (int j = 0; j < m[i]; j++) {
                cin >> p[i][j].k;
                sc[i] += p[i][j].k;
            }
        }
        if (slen >= sm) {
            cout << "0\n";
            continue;
        }
        P.clear();
        Q.clear();
        for (int i = 1; i <= n; i++) {
            for (auto y : p[i]) {
                if (y.w < sl || y.w > sr) continue;
                int w = max(0LL, y.k - (sc[i] - r[i]));
                P[y.w] += w;
                w = min(r[i] - l[i], w);
                Q[y.w] += w;
            }
        }
        int ans = llf;
        for (int i = sl; i <= sr; i++) {
            ans = min(ans, P[i] - min(Q[i], sr - i));
        }
        cout << ans << '\n';
    }
    return 0;
}