#include <iostream>
using namespace std;
const int N = 110;
struct node {
    int x, y;
} p[N];
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int area(int a, int b) { return p[a].x * p[b].y - p[a].y * p[b].x; }
int t;
int main() {
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        int n, x, y, num = 0, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x >> y;
            num += gcd(abs(x), abs(y));
            p[i].x = x + p[i - 1].x, p[i].y = y + p[i - 1].y;
            sum += area(i - 1, i);
        }
        sum = abs(sum);
        printf("Scenario #%d:\n", _);
        printf("%d %d %.1f\n\n", (sum - num + 2) >> 1, num, sum * 0.5);
    }
    return 0;
}