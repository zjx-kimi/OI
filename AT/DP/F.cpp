#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
char a[N] ,b[N];
int n, m;
int f[N][N];
int g[N][N];
int h[N][N];
void print(int x, int y) {
	if(x == 0 || y == 0) return;
	print(g[x][y], h[x][y]);
	if(a[x] == b[y]) cout << a[x];
}
int main() {
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = INT_MAX;
			if(a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
				g[i][j] = i - 1;
				h[i][j] = j - 1;
			}else {
				if(f[i - 1][j] > f[i][j - 1]) {
					f[i][j] = f[i - 1][j];
					g[i][j] = i - 1;
					h[i][j] = j;
				}else{
					f[i][j] = f[i][j - 1];
					g[i][j] = i;
					h[i][j] = j - 1;
				}
			} 
		}
	}
	print(n, m);
	return 0;
} 