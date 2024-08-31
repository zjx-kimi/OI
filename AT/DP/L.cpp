#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3001;
int n, a[N];
int sum[N];
int A[N][N];
int B[N][N];
signed main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        A[i][i] = a[i]; 
    }
    for(int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            const int first = j;
            const int end = i + j;
            A[first][end] = max(B[first + 1][end] + a[first],B[first][end - 1] + a[end]);
            B[first][end] = sum[end] - sum[first - 1] - A[first][end];
        }
    }
    cout << A[1][n] - B[1][n];
}   