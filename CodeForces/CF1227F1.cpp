#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, h, arr[2005], c[2005][2005], cnt, Cnt;
int main () {
	cin >> n >> h;
	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= n; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) 
		if (arr[i] == arr[i + 1]) 
			cnt++;
		else
			Cnt++;
	for (int i = 1; i <= n; i++) 

}