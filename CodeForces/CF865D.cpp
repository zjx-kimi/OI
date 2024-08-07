#include <bits/stdc++.h>
using namespace std;
priority_queue <long long, vector <long long>, greater <long long> > q;
int main() {
	long long n, x, ans = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		q.push(x);
		if (x > q.top()) {
			ans += x - q.top();
			q.pop();
			q.push(x);
		}
	}
	cout << ans << '\n';
}
