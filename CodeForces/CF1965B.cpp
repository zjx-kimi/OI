#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;

        int i = 0;
        while ((1 << (i + 1)) <= k) {
            i++;
        }

        vector<int> ans = {k - (1 << i), k + 1, k + 1 + (1 << i)};

        for (int j = 0; j < 20; j++) {
            if (j != i) {
                ans.push_back(1 << j);
            }
        }

        cout << ans.size() << endl;
        for (int num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

