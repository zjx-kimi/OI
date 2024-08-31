#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y, data;
} p[100];
int n, m, mp[11][11], f[11][11][11][11];
int main() {
    scanf("%d", &n);
    while (1) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (!a && !b && !c) break;
        p[++m].x = a;
        p[m].y = b;
        p[m].data = c;
    }
    for (int i = 1; i <= m; i++) mp[p[i].x][p[i].y] = p[i].data;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                int l = i + j - k;
                if (l <= 0) break;
                f[i][j][k][l] = max(f[i - 1][j][k - 1][l], max(f[i - 1][j][k][l - 1], max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])));
                if (i == k && j == l)
                    f[i][j][k][l] += mp[i][j];
                else
                    f[i][j][k][l] += mp[i][j] + mp[k][l];
            }
    printf("%d\n", f[n][n][n][n]);
    return 0;
}