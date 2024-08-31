#include<bits/stdc++.h>
using namespace std;
long long n, ans, f[100010];
int main(){
    cin >> n;
    for(int i = n; i; i--){
        f[i] = n / i * (n / i);
        for (int j = i << 1; j <= n; j += i) f[i] -= f[j];
        ans += f[i] * i;
    }
    cout << ans << '\n';
    return 0;
}