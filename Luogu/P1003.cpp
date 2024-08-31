#include<bits/stdc++.h> 
using namespace std;
int n, i, x, y, ok = 1;
int a[10010], b[10010], g[10010], k[10010], s[10010];
int main(){
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> g[i] >> k[i];
		s[i] = i;
	}
	cin >> x >> y;
	for (i = n; i >= 1; i--) {
		if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i]) {
			ok = 0;
			cout << s[i];
			break;
		}
	}
	if (ok) cout << "-1";
	return 0;
}