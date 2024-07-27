// Problem: A - Glutton Takahashi
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 105;
string s[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i < n - 1; i++)
		if (s[i] == s[i + 1] && s[i] == "sweet")
			return cout << "No", 0;
	return cout << "Yes", 0 << '\n';
}