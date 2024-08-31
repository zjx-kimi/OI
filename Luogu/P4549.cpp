#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int ans = 0, tmp;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &tmp);
        ans = __gcd (ans, abs(tmp));
    }
    printf("%d", ans);
}

