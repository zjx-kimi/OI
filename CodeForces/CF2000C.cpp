#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;
int n, q;
int arr[N];
string s;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> q;
    while (q--) {
        cin >> s; 
        if (s.size() != n) {puts("NO"); continue;}
        s = " " + s;
        map <int, char> mp;
        map <char, int> mp2;
        bool f = 0;
        for (int i = 1; i <= n; i++) {
            if (mp[arr[i]] == 0 && mp2[s[i]] == 0) {
                mp[arr[i]] = s[i];
                mp2[s[i]] = arr[i];
            } else if (mp[arr[i]] == 0 && mp2[s[i]] != 0) {
                puts("NO"); f = 1; break;
            } else if (mp[arr[i]] != 0 && mp2[s[i]] == 0) {
                puts("NO"); f = 1; break;
            } else if (mp[arr[i]] != s[i] || mp2[s[i]] != arr[i]) {
                puts("NO"); f = 1; break;
            }
        }
        if (!f) puts("YES");
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}