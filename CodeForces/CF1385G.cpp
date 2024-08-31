#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
int fa[MAXN];
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void merge(int x, int y) { fa[find(x)] = find(y); }
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, a, b, ok = true;
        cin >> n;
        for (int i = 1; i <= n * 2; ++i)
            fa[i] = i;
        vector<vector<int>> P(n + 5), Q(n + 5);
        for (int i = 1; i <= n; ++i)
            cin >> x, P[x].push_back(i);
        for (int i = 1; i <= n; ++i)
            cin >> x, Q[x].push_back(i);
        for (int i = 1; i <= n; ++i)
        {
            if (P[i].size() == 2 && Q[i].size() == 0)
            {
                a = P[i].front(), b = P[i].back();
                merge(a, b + n);
                merge(a + n, b);
            }
            else if (P[i].size() == 0 && Q[i].size() == 2)
            {
                a = Q[i].front(), b = Q[i].back();
                merge(a, b + n);
                merge(a + n, b);
            }
            else if (P[i].size() == 1 && Q[i].size() == 1)
            {
                a = P[i].front(), b = Q[i].front();
                merge(a, b);
                merge(a + n, b + n);
            }
            else
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        vector<vector<int>> each(n * 2 + 5);
        for (int i = 1; i <= n; ++i)
            each[find(i)].push_back(i);
        for (int i = 1; i <= n; ++i)
            if (each[i].size() > each[i + n].size())
                ans.insert(ans.end(), each[i].begin(), each[i].end());
            else
                ans.insert(ans.end(), each[i + n].begin(), each[i + n].end());
        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}