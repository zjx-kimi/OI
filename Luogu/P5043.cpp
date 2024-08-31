#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1001;
int ans[N][N], n, m, x;
vector <int> Edge[N];
int Hash(int x, int f) {
    int ans = N, top = 0;
    vector <int> q;
    for (int i : Edge[x])
        if (i != f) 
            q.push_back(Hash(i, x));
    sort(q.begin(), q.end());
    for (int i : q) ans = ans * 2333 + i;
    return ans * 2333 + N + 1;
}
signed main() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) Edge[j].clear();
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x != 0) {
                Edge[x].push_back(j);
                Edge[j].push_back(x);
            }
        }
        for (int j = 1; j <= n; j++) ans[i][j] = Hash(j, 0);
        sort(ans[i] + 1, ans[i] + n + 1);
        for (int j = 1, k = 0; j <= i; j++) {
            while (k <= n)
                if (ans[i][++k] != ans[j][k]) break;
            if (k > n) {
                printf("%lld\n", j);
                break;
            }
        }
    }
    return 0;
}