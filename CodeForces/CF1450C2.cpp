#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int t, n, k;
string s[N];
int cnt[3][2];
void solve() {
	cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = cnt[2][0] = cnt[2][1] = 0;
	cin >> n, k = n * n;
	for (int i = 1; i <= n; i++) 
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n; j++) 
			if (s[i][j] == 'X') cnt[(i + j) % 3][0]++;
			else if (s[i][j] == 'O') cnt[(i + j) % 3][1]++;
			else k--;
	if (cnt[0][0] + cnt[1][1] <= k / 3) {
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < n; j++)
				if ((i + j) % 3 == 0 && s[i][j] == 'X') s[i][j] = 'O';
				else if ((i + j) % 3 == 1 && s[i][j] == 'O') s[i][j] = 'X'; 
	}
	else if (cnt[1][0] + cnt[2][1] <= k / 3) {
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < n; j++)
				if ((i + j) % 3 == 1 && s[i][j] == 'X') s[i][j] = 'O';
				else if ((i + j) % 3 == 2 && s[i][j] == 'O') s[i][j] = 'X'; 
	}
	else if (cnt[2][0] + cnt[0][1] <= k / 3) {
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < n; j++)
				if ((i + j) % 3 == 2 && s[i][j] == 'X') s[i][j] = 'O';
				else if ((i + j) % 3 == 0 && s[i][j] == 'O') s[i][j] = 'X'; 
	}
	for (int i = 1; i <= n; i++) cout << s[i] << '\n';
}
int main() {
	cin >> t;
	while (t--) solve();
}