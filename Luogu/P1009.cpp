#include <bits/stdc++.h>
using namespace std;
struct big_int {
	int len;
	int arr[10000] = {};//1个位
};
big_int input(int x) {
	big_int num;
	int i = 1;
	while (x) {
		num.arr[i] = x % 10;
		x /= 10;
		i++;
	}
	num.len = i - 1;
	return num;
}
void output(big_int num) {
	for (int i = num.len; i >= 1; i--) cout << num.arr[i];
}
big_int cheng(big_int a, big_int b) {
	big_int ans;
	for (int i = 1; i <= a.len; i++) {
		for (int j = 1; j <= b.len; j++) {
			ans.arr[i + j - 1] += a.arr[i] * b.arr[j];
		}
	}
	ans.len = a.len + b.len - 1;
	for (int i = 1; i <= ans.len; i++) {
		ans.arr[i + 1] += ans.arr[i] / 10;
		ans.arr[i] %= 10;
	}
	if (ans.arr[ans.len + 1]) ans.len++;
	return ans;
}
big_int jia(big_int a, big_int b) {
	big_int ans;
	ans.len = max(a.len, b.len);
	for (int i = 1; i <= ans.len; i++) {
		ans.arr[i] += a.arr[i] + b.arr[i];
		ans.arr[i + 1] += ans.arr[i] / 10;
		ans.arr[i] %= 10;
	}
	if (ans.arr[ans.len + 1]) ans.len++;
	return ans;
}
big_int work(int a) {
	big_int ans;
	for (int i = 1; i <= a; i++) {
		big_int res = {1, {0, 1}};
		for (int j = 1; j <= i; j++) {
			res = cheng(res, input(j));
		}
		ans = jia(ans, res);
	}
	return ans;
}
int main() {
	int a;
	cin >> a;
	output(work(a));
	return 0;
}