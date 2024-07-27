#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, op, x, y;
int sta[N], ls[N], rs[N], cnt;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	cin >> n;
	while (n--) {
		cin >> op >> x >> y;
		updata()
		cout << sta[1] << '\n';
	}
}