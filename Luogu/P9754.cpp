#include <bits/stdc++.h>
#define Byte 1
#define Short 2
#define Int 4
#define Long 8
#define ll long long
using namespace std;
const int N = 1e7 + 9;
int n, op, cnt;
string s, type, name;
/*      定义 struct     */

struct Struct {
	int len, maxx; // len 表示长度; maxx 表示对齐
	vector <int> members; // 结构体中的成员类型
	vector <int> name;
};

map <string, int> mp = { 
	{"bool", 1},
	{"short", 2},
	{"int", 3},
	{"long", 4}
}; // Struct 的 id
map <int, string> MP = {
	{1, "bool"}, 
	{2, "short"}
}; // id 的 name
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n;
    while (n--) {
    	cin >> op;
    	if (op == 1) {

    	}
    }
    return 0;
}
/*
struct a{
 short aa; // 0-1
 int ab;   // 4-7
};
struct b{
	a ba;
	long bb;
};
b x;
x.ba.ab;
*/