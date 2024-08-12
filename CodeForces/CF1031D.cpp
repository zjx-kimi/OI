#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2005;
int n, k, max_len_a;
char mp[N][N];
int dp[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  	for (int j = 1; j <= n; j++)
  		cin >> mp[i][j];
  dp[1][1] = (mp[1][1] != 'a');
  for (int i = 2; i <= n; i++) dp[1][i] = dp[1][i - 1] + (mp[1][i] != 'a');
  for (int i = 2; i <= n; i++) dp[i][1] = dp[i - 1][1] + (mp[i][1] != 'a');
  for (int i = 2; i <= n; i++) {
  	for (int j = 2; j <= n; j++) {
  		dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (mp[i][j] != 'a');
  	}
  }
  for (int i = 1; i <= n; i++) 
  	for (int j = 1; j <= n; j++) 
  		if (dp[i][j] == k) 
  			max_len_a = max(max_len_a, i + j - 1);
  queue <pair <int, int> > q;
  for (int i = 1; i <= n; i++) 
  	for (int j = 1; j <= n; j++) 
  		if (dp[i][j] == k && max_len_a == i + j - 1) 
  		  q.push({i, j});
  if (k == 0) { q.push({1, 1}); cout << mp[1][1]; max_len_a = 1; }
  else if (k >= dp[n][n]) {
  	for (int i = 1; i < n * 2; i++) cout << 'a';
  	return 0;
  } else {
  	for (int i = 1; i <= max_len_a; i++) cout << 'a';
  }
  for (int i = max_len_a + 1; i < n * 2; i++) {
  	char minn = 'z';
  	queue < pair <int, int> > qq;
  	while(qq.size()) qq.pop();
  	queue < pair <int, int> > qqq = q;
  	while (q.size()) {
  		int x = q.front().first, y = q.front().second;
  		q.pop();
		
  		minn = min({minn, (y + 1 <= n ? mp[x][y + 1] : 'z'), (x + 1 <= n ? mp[x + 1][y] : 'z')});
  	}
  	while (qqq.size()) {
  		int x = qqq.front().first, y = qqq.front().second;
  		qqq.pop();
  		if (y + 1 <= n && mp[x][y + 1] == minn) qq.push({x, y + 1});
  		if (x + 1 <= n && mp[x + 1][y] == minn) qq.push({x + 1, y});
  	}
  	q = qq;
  	cout << minn;
  }
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}