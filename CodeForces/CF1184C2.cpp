#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 9;
const int add = 2e6;
const int Max = 5e6 + 10;
int n, r, x, y, R = 0, ans;
struct Node {
	int x, y;
} points[N];
bool cmp (Node x, Node y) {
	return x.x <= y.x;
}
deque <int> d;
class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        data.assign(4 * n, 0); // 存储线段树的节点
        lazy.assign(4 * n, 0); // 懒惰标记
    }

    // 更新区间 [l, r] 增加值 x
    void update(int l, int r, int x) {
        update(1, 0, n - 1, l, r, x);
    }

    // 查询区间 [0, n-1] 的最大值
    int query() {
        return data[1]; // 根节点存储整个区间的最大值
    }

private:
    int n; // 数组大小
    vector<int> data; // 线段树节点数组
    vector<int> lazy; // 懒惰标记数组

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            data[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int x) {
        push(node, start, end);
        if (r < start || l > end) return;
        if (l <= start && end <= r) {
            data[node] += x;
            if (start != end) {
                lazy[2 * node] += x;
                lazy[2 * node + 1] += x;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, x);
        update(2 * node + 1, mid + 1, end, l, r, x);
        data[node] = max(data[2 * node], data[2 * node + 1]);
    }
} tree(6e6);
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
    	cin >> x >> y;
    	points[i] = {x - y + add, x + y + add};
    }
    sort (points + 1, points + n + 1, cmp);
    for (int i = 0; i <= Max; i++) {
    	while (R + 1 <= n && points[R + 1].x <= i + r) {
    	    R++;
    	    d.push_back(R);
    	    tree.update(points[R].y - r, points[R].y + r, 1);
    	}
    	while (d.size() && points[d.front()].x < i - r) {
    	    tree.update(points[d.front()].y - r,points[d.front()].y + r, -1);
    	    d.pop_front();
    	}
    	ans = max(ans, tree.query());
    }
    cout << ans << '\n';
    return 0;
}