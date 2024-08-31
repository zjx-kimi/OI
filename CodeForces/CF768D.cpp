#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e3+5;
double dp[N][M];
int K,Q;
int p[N],n,m=10000;
int main(){
    cin>>n>>Q;
    for(int i=1;i<=Q;i++){
        scanf("%d",&p[i]);
    }
    dp[0][0]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = dp[i - 1][j] * (double) j / n + dp[i - 1][j - 1] * (double)(n - j + 1) / (n);
    for(int i=1;i<=Q;i++){
        int t = 1;
        for (int j = 1; j <= m; j++) if (dp[j][n] < p[i] * 0.0005) t++;
        printf ("%d\n",t);
    }
    return 0;
}
