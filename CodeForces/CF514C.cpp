#include <bits/stdc++.h>
using namespace std;
const int N = 6e5;
int n, m;
string s;
struct {
	int ch[N][3];
	int ex[N], cnt;
	int insert (string x) {
		int p = 0;
		for (char i : x) {
			if (ch[p][i - 'a'] == 0) ch[p][i - 'a'] = ++cnt;
			p = ch[p][i - 'a'];
		}
		ex[p] = true;
		return p;
	}
	bool query (int i, int o, bool changed) {
		if (i == s.size()) return changed && ex[o];
		if (ch[o][s[i] - 'a'] && query(i + 1, ch[o][s[i] - 'a'], changed)) return true;
		if (changed) return 0;
		for (int j = 0; j <= 2; j++) 
			if (ch[o][j] && j != s[i] - 'a' && query(i + 1, ch[o][j], true)) 
				return true;
		return false;
	} 
} Trie;
int main() {
	cin >> n >> m;
	while (n--) {
		cin >> s; Trie.insert(s);
	}
	while (m--) {
		cin >> s;
		cout << (Trie.query(0, 0, 0) ? "YES\n" : "NO\n");
	}
}