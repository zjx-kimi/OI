#include <bits/stdc++.h>
using namespace std;
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j) continue;
			for (int k = 1; k <= 9; k++) {
				if (i == k) continue;
				if (j == k) continue;
				int a = i * 100 + j * 10 + k, b = a * 2, c = a * 3;
				if (c > 987) continue;
				short t[10] = {};
				bool flag = true;
				t[i] ++, t[j] ++, t[k] ++, t[b % 10]++, t[b / 10 % 10]++, t[b / 100]++, t[c % 10]++, t[c / 10 % 10]++, t[c / 100]++;
				for (int i = 1; i <= 9; i++) {
					if (t[i] != 1) {
						flag = false;
						break;
					}
				}
				if (flag) printf("%d %d %d\n", a, b, c);
			}
		}
	}
	return 0;
}