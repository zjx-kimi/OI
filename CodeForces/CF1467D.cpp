#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,q;
const int N=5100;
int dp[N][N],a[N][N];
int cnt[N],v[N];
const int mod=1e9+7;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int j=1;j<=k;j++)
        for(int i=1;i<=n;i++)
            dp[i][j]=(dp[i-1][j-1]+dp[i+1][j-1])%mod;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            a[i][j]=dp[i][j]*dp[i][k-j]%mod;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cnt[i]+=a[i][j];
            cnt[i]%=mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=cnt[i]*v[i];
        ans%=mod;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ans+=(y-v[x])*cnt[x];
        v[x]=y;
        ans%=mod;ans+=mod;ans%=mod;
        cout<<ans<<endl;
    }
}