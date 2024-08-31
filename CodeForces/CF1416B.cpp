#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int t, n, sum;
int arr[N];
void solve() {
	cin >> n, sum = 0;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) sum += arr[i];
	if (sum % n) return puts("-1"), void();
	sum /= n;
	cout << 3 * n - 3 << '\n';
	for (int i = 2; i <= n; i++) {
		int q = (arr[i] + i - 1) / i * i;
		cout << 1 << ' ' << i << ' ' << q - arr[i] << '\n'; // step 1.
		cout << i << ' ' << 1 << ' ' << q / i << '\n';
	}
	for (int i = 2; i <= n; i++) 
		cout << 1 << ' ' << i << ' ' << sum << '\n';
}
int main() {
	cin >> t;
	while (t--) solve();
}
/*
1.将 a[i] 变为 i 的倍数. 
2.将 a[i] 变为 0.  
3.将 a[1] 的值平均分给每个 a[i].
*/