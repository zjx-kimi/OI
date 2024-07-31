#include <bits/stdc++.h>
using namespace std;
long long x, y;
void exgcd(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 7;
        return;
    }
    exgcd(b, a % b);
    long long tx = x;
    x = y;
    y = tx - a / b * y;
}
int main() {
    long long a, b;
    cin >> a >> b;
    exgcd(a, b);
    x = (x % b + b) % b;
    printf("%lld\n", x);
    return 0;
}