#include <bits/stdc++.h>
using namespace std;
int n, k;
bool f[100005];
int arr[100005];
int main() {
	cin >>  n >> k;
	for (int i = 1; i <= n ; i++) cin >> arr[i];
	for (int i = 1; i <= k; i++) { // 枚举每个石头数的方案
		for (int j = 1; j <= n; j++) {
			if (arr[j] <= i) {
				if (!f[i - arr[j]]) {
					f[i] = 1;
					break;
				}
			}
		}
	}
	if(f[k]) cout << "First";
	else cout << "Second";
}