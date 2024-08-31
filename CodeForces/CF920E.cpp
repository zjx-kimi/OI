#include <bits/stdc++.h>
using namespace std;
const int N = 200010;

int a, b, in[N], fa[N], scc, bel[N], siz[N];
bool vis[N], vis1[N];
vector<int> st[N];

inline int f(int n) {
    return fa[n] == n ? n : fa[n] = f(fa[n]);
}

signed main()
{
	cin >> a >> b;
    int x, y;
    for (int i = 1; i <= b; i++)
    {cin >> x >> y;
        st[x].push_back(y);
        st[y].push_back(x);
    }
    int mx = 1;
    for (int i = 1; i <= a; i++)
        fa[i] = i;
    for (int i = 2; i <= a; i++)
        if (st[i].size() < st[mx].size())//找到度最小的点
            mx = i;
    for (int i = 0; i < st[mx].size(); i++)
        vis[st[mx][i]] = 1;
    for (int i = 1; i <= a; i++)
        if (!vis[i])
            fa[i] = mx;
    for (int i = 1; i <= a; i++)
    {
        if (!vis[i] || i == mx)//对其他没有联通的点进行合并操作
            continue;
        memset(vis1, 0, sizeof(vis1));
        int f1 = f(i);
        for (int j = 0; j < st[i].size(); j++)
            vis1[st[i][j]] = 1;
        for (int j = 1; j <= a; j++)//暴力合并（（（并非
            if (!vis1[j])
                fa[f(j)] = f1;
    }
    for (int i = 1; i <= a; i++)
        if (fa[i] == i)
            bel[i] = ++scc;
    for (int i = 1; i <= a; i++)
        siz[bel[f(i)]]++;
    sort(siz + 1, siz + scc + 1);
    printf("%d\n", scc);
    for (int i = 1; i <= scc; i++)
        printf("%d ", siz[i]);
    return 0;
}
