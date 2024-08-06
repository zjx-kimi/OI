#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(200 * 1000 + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	
	int l = 0, r = 0;
	int ans = cnt[a[0]];
	for (int i = 0; i < int(a.size()); ++i) {
		int j = i + 1;
		int sum = cnt[a[i]];
		while (a[j] - a[j - 1] == 1 && cnt[a[j]] > 1) {
			sum += cnt[a[j]];
			++j;
		}
		int cr = j - 1;
		if (j < n && a[j] - a[j - 1] == 1) {
			sum += cnt[a[j]];
			cr = j;
		}
		if (ans < sum) {
			ans = sum;
			l = i;
			r = cr;
		}
		i = j - 1;
	}
	
	cout << ans << endl;
	for (int c = 0; c < cnt[a[l]]; ++c) cout << a[l] << " ";
	for (int i = l + 1; i < r; ++i) {
		for (int c = 0; c < cnt[a[i]] - 1; ++c) cout << a[i] << " ";
	}
	for (int c = 0; l != r && c < cnt[a[r]]; ++c) cout << a[r] << " ";
	for (int i = r - 1; i > l; --i) cout << a[i] << " ";
	cout << endl;
	
	return 0;
}