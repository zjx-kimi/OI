#include <bits/stdc++.h>
#define PII pair<int, int>

using namespace std;
const int D = 510, S = 5010;
int d, s;
bool vis[D][S];
queue<PII> q;
pair<PII, int> p[D][S];

inline void bfs() {
    vis[0][0] = true;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 10; i++) {
            int dx = (x * 10 + i) % d, dy = y + i;
            if (dy <= s && !vis[dx][dy]) {
                vis[dx][dy] = true;
                p[dx][dy] = make_pair(make_pair(x, y), i);
                q.push(make_pair(dx, dy));
            }
        }
    }
}

void print(int x, int y) {l
    if (!x && !y) return;
    print(p[x][y].first.first, p[x][y].first.second);
    putchar('0' + p[x][y].second);
}

int main() {
    scanf("%d%d", &d, &s);
    bfs();
    if (!vis[0][s])
        puts("-1");
    else
        print(0, s);
    return 0;
}