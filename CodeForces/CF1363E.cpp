#include <bits/stdc++.h>
#define MAX 500005
#define ll long long
using namespace std;

int n, cnt;
int head[MAX], vet[MAX], Next[MAX], b[MAX], c[MAX], s[MAX][2];
ll a[MAX], ans;

void add(int x, int y){
    cnt++;
    Next[cnt] = head[x];
    head[x] = cnt;
    vet[cnt] = y;
}

void dfs(int x, int fa){
    if(x != 1) a[x] = min(a[x], a[fa]);
    s[x][b[x]] += (b[x]!=c[x]);
    for(int i = head[x]; i; i = Next[i]){
        int v = vet[i];
        if(v == fa) continue;
        dfs(v, x);
        s[x][0] += s[v][0], s[x][1] += s[v][1];
    }
    int t = min(s[x][0], s[x][1]);
    ans += a[x]*t*2;
    s[x][0] -= t, s[x][1] -= t;
}

int main()
{
    cin >> n;
    int s1 = 0, s2 = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld%d%d", &a[i], &b[i], &c[i]);
        s1 += b[i], s2 += c[i];
    }

    int x, y;
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    if(s1 != s2){
        puts("-1");
        return 0;
    }
    dfs(1, 0);
    cout << ans << endl;

    return 0;
}
