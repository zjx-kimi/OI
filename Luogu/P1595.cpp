#include <bits/stdc++.h>
using namespace std;
long long f[25], n;
int main() {
    cin >> n;
    f[1] = 0, f[2] = 1, f[3] = 2;
    for (int i = 4; i <= n; i++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
    printf("%lld", f[n]);
    return 0;
}