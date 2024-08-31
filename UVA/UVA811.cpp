#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const double sp = 1000000000;
int x[N], y[N], val[N], len[N];
bool b[N];
struct Node {
    double x, y, k;
} node[N], s[N];
double chachen(double x1, double y1, double x2, double y2) { return x1 * y2 - x2 * y1; }
double getdis(double x1, double y1, double x2, double y2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
bool cmp(Node i, Node j) {
    if (i.k == j.k) return fabs(i.x - node[0].x) > fabs(j.x - node[0].x);
    if (i.k == sp) return 0;
    if (j.k == sp) return 1;
    return i.k < j.k;
}
double solve(int len, int fn) {
    int n = 0, sn = 1, sm = 0;
    for (int i = 1; i <= fn; i++) {
        if (b[i]) continue;
        node[++n].x = x[i];
        node[n].y = y[i];
    }
    for (int i = 1; i <= n; i++) {
        if (node[i].y > node[sn].y)
            sn = i;
        else if (node[i].y == node[sn].y && node[i].x > node[sn].x)
            sn = i;
    }
    node[0] = node[sn];
    for (int i = 1; i <= n; i++) {
        double x = node[i].x - node[0].x;
        double y = node[i].y - node[0].y;
        if (y == 0)
            node[i].k = sp;
        else
            node[i].k = x / y;
    }
    sort(node + 1, node + n + 1, cmp);
    s[++sm] = node[0];
    node[0].k = 1e9;
    for (int i = 1; i <= n; i++) {
        double x = node[i].x, y = node[i].y;
        while (sm > 1) {
            double x1 = s[sm].x, y1 = s[sm].y;
            double x2 = s[sm - 1].x, y2 = s[sm - 1].y;
            x2 -= x1, y2 -= y1;
            x1 -= x, y1 -= y;
            if (chachen(x1, y1, x2, y2) < 0)
                sm--;
            else
                break;
        }
        s[++sm] = node[i];
    }
    double temp = 0;
    double x = s[sm].x, y = s[sm].y;
    sm--;
    while (sm) {
        double x1 = s[sm].x, y1 = s[sm].y;
        sm--;
        temp += getdis(x, y, x1, y1);
        x = x1, y = y1;
    }
    return temp;
}
int n, ans = 1e9, an[N], ann;
double anl;
void dfs(int num, int l, int v) {
    if (num == n) {
        double flag = solve(l, n);
        if ((flag <= l) && (ans > v || (ans == v && anl > l - flag))) {
            ans = v;
            ann = 0;
            anl = (double)l - flag;
            for (int i = 1; i <= n; i++) {
                if (!b[i]) continue;
                an[++ann] = i;
            }
        }
        return;
    }
    dfs(num + 1, l, v);
    b[num + 1] = 1;
    dfs(num + 1, l + len[num + 1], v + val[num + 1]);
    b[num + 1] = 0;
}
int main() {
    int nn = 0;
    while (cin >> n) {
        if (n == 0) break;
        if (nn) printf("\n");
        printf("Forest %d\n", ++nn);
        ans = 1e9;
        anl = 1e9;
        int tl = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &x[i], &y[i], &val[i], &len[i]);
            tl += len[i];
        }
        dfs(0, 0, 0);
        printf("Cut these trees:");
        for (int i = 1; i <= ann; i++) printf(" %d", an[i]);
        printf("\nExtra wood: %.2lf\n", anl);
    }
    return 0;
}