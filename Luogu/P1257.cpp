#include <cmath>
#include <cstdio>
using namespace std;
long long n, x[10005], y[10005];
double ans = 1e18;
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) { scanf("%lld%lld", &x[i], &y[i]); }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) < ans) { ans = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])); }
        }
    }
    printf("%.4lf", ans);
    return 0;
}