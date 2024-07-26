#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int t, n, k;
string s[N];
int cnt[3][2];
void solve() {
	cin >> n, k = n * n;
	for (int i = 1; i <= n; i++) 
		cin >> s[i], s[i] = " " + s[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (s[i][j] == 'X') cnt[(i + j) % 3][0]++;
			else if (s[i][j] == 'O') cnt[(i + j) % 3][1]++;
			else k--;
			

}
int main() {
	cin >> t;
	while (t--) solve();
}