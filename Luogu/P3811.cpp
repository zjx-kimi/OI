#include <bits/stdc++.h>
#define int long long
using namespace std;
int inv[3000010], n, p;
signed main()
{
    cin >> n >> p;
    inv[1] = 1;
    puts("1");
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
        printf("%lld\n", inv[i]);
    }
}
