#include <bits/stdc++.h>
using namespace std;

struct node {
    double x, y;
    node() {}
    node(int _x, int _y) { x = _x, y = _y; }
    bool operator<(const node &t) const { return x < t.x || (x == t.x && y < t.y); }
    node operator-(node &t) { return node(x - t.x, y - t.y); }
} a[100005], b[100005];

double calculateCrossProduct(node A, node B) { return A.x * B.y - A.y * B.x; }

double calculateLength(node A, node B) { return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); }

bool compare(node A, node B, node base) {
    double crossProduct = calculateCrossProduct(A - base, B - base);
    if (crossProduct > 0)
        return true;
    else if (crossProduct == 0) {
        if ((A - base).y > 0 && (B - base).y > 0)
            return calculateLength(A, base) > calculateLength(B, base);
        else if ((A - base).y < 0 && (B - base).y < 0)
            return calculateLength(A, base) < calculateLength(B, base);
        else
            return (A - base).y < 0;
    }
    else
        return false;
}

int main() {
    int n, m, t;
    char c;

    cin >> t;
    while (t--) {
        cin >> n;
        m = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> c;
            if (c == 'Y') b[++m] = a[i];
        }
        
        cout << m << '\n';
        sort(b + 1, b + m + 1);
        sort(b + 2, b + m + 1, [&](node A, node B) { return compare(A, B, b[1]); });

        for (int i = 1; i <= m; i++) {
            cout << fixed << setprecision(0) << b[i].x << ' ' << b[i].y << '\n';
        }
    }

    return 0;
}
