#include <bits/stdc++.h>
using namespace std;
int n, cnt, nxt[1000006], ans[1000006], vis[1000006];
vector<int> a[1000006], b[1000006];
void solve_singular(int x) {
    for (int i = 0, j = a[x].size() / 2 + 1; i < a[x].size() / 2; i++, j++) {
        ans[a[x][i]] = a[x][j];
        ans[a[x][j]] = a[x][i + 1];
    }
    ans[a[x][a[x].size() / 2]] = a[x][0];
}
void solve_even(int x, int y) {
    for (int i = 0; i < a[x].size(); i++) {
        ans[a[x][i]] = a[y][i];
        ans[a[y][i]] = a[x][(i + 1) % a[x].size()];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nxt[i];
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            a[++cnt].push_back(i);
            vis[i] = true;
            int x = nxt[i];
            while (!vis[x]) {
                vis[x] = 1;
                a[cnt].push_back(x);
                x = nxt[x];
            }
            b[a[cnt].size()].push_back(cnt);
        }
    }

    for (int i = 2; i <= n; i += 2) 
        if (b[i].size() & 1)  return puts("-1"), 0;
    for (int i = 1; i <= n; i += 2) 
        for (int j = 0; j < b[i].size(); j++) 
            solve_singular(b[i][j]);
    for (int i = 2; i <= n; i += 2)
        for (int j = 0; j < b[i].size(); j += 2) 
            solve_even(b[i][j], b[i][j + 1]);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}