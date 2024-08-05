#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, s, k;
int solve(int s, int k)
{
    int ans = s * k;
    int x = max(min((5 * k - s) / 40, k / 4), 0ll);
    ans = max(ans, -80 * x * x + (20 * k - 4 * s) * x + s * k);
    x = min(x + 1, k / 4);
    ans = max(ans, -80 * x * x + (20 * k - 4 * s) * x + s * k);
    return ans;
}
int calc()
{
    cin >> s >> k;
    if (s % 10 == 0)
        return s * k;
    if (s % 10 == 5)
        return max(s * k, (s + 5) * (k - 1));
    int ans = s * k;
    if (s % 2)
        s += s % 10, k--;
    for (int i = 1; i <= 4; i++)
    {
        if (k <= 0)
            break;
        ans = max(ans, solve(s, k)), s += s % 10, k--;
    }
    return ans;
}
signed main()
{
    cin >> t;
    while (t--)
        cout << calc() << endl;
    return 0;
}