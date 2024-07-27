// Problem: C - Minimum Glutton
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, la, lb, aa,ab, sum;
struct ss{int a, b;} s[N];
bool cmp(ss a, ss b) {return a.a > b.a;}
bool cmp2(ss a, ss b) {return a.b > b.b;}
signed main() {
	cin >> n >> la >> lb;
	for (int i = 1; i <= n; i++) cin >> s[i].a;
	for (int i = 1; i <= n; i++) cin >> s[i].b;
	sort (s + 1, s + n + 1, cmp);
	aa = ab = n;
	sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += s[i].a;
		if (sum > la) {
			aa = i;
			break;
		}
	}
	
	sort (s + 1, s + n + 1, cmp2);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += s[i].b;
		if (sum > lb) {
			ab = i;
			break;
		}
	}
	cout << min(aa, ab);
}