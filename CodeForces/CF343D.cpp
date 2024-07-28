// Problem: D. Water Tree
// Contest: Codeforces - Codeforces Round 200 (Div. 1)
// URL: https://codeforces.com/problemset/problem/343/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, Q, x, y;
vector <int> edge[N];
void dfs()
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	cin >> Q;
	while (Q--) {

	}
}
/*
考虑使用线段数
*/