#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;
int n, c, Ans;
int arr[N];
int minn[N];
int cnt[N];
int ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  cin >> n >> c;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
  	minn[arr[i]] = min(minn[arr[i]], cnt[arr[i]] - cnt[c]);
  	cnt[arr[i]]++;
  	ans[i] = cnt[arr[i]] - cnt[c] - minn[arr[i]];
  	Ans = max(ans[i], Ans);
  }
  cout << Ans + cnt[c] << '\n';
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}