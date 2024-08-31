#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;

int n;

int arr[N];

void solve () {
  cin >> n;
  int sum = 0, x = 1;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1); // 排序
  n = unique(arr + 1, arr + n + 1) - arr - 1; // 去重
  int flag = -1;
  for (int i = 1; i <= n; i++)
      if (arr[i] != i) {
          flag = i - 1;
          break;
      }
  if (flag % 2 == 1 && flag != n || n % 2 == 0 && flag == -1)
      cout << "Bob" << endl;
  else
      cout << "Alice" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifdef kimi
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) solve();
  cerr << "Time used = " << (double)clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}