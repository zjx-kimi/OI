// Problem: B - Grid Walk
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, x, y;
string s[N], t;
int main() {
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) cin >> s[i], s[i] = " " + s[i];
	cin >> t;
	for (char i : t) {
		if (i == 'L' && s[x][y - 1] == '.') y--;
		if (i == 'R' && s[x][y + 1] == '.') y++;
		if (i == 'U' && s[x - 1][y] == '.') x--;
		if (i == 'D' && s[x + 1][y] == '.') x++;
	}
	cout << x << ' ' << y << '\n';
	 
	
}