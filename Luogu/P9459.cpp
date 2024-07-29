#include <bits/stdc++.h>
using namespace std;
int n;
string a, b, c, d;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        if (a[0] == b[0] && a[0] == 'y' && c == "ding" && d == "zhen")
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}