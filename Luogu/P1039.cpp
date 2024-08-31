#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100;
int m, n, p; // 同学数; 说谎数量; 证言数量
string s[N]; // 第 i 个人的名字
map <string, int> id; // 名字为 s 的 id
map <string, int> Days = {
	{"Monday", 1},
	{"Tuesday", 2},
	{"Wednesday", 3},
	{"Thursday", 4},
	{"Friday", 5}, 
	{"Saturday", 6}, 
	{"Sunday", 7}
};
int trust[N]; // 是否可信
struct saying{
	int say; // 说话人的 id
	int people; // 说的人
	int yes; // 是否肯定; 1 为肯定; 0 为否定
	int days; // 表明的星期
};
vector <saying> P;
set <int> crime; // 犯罪人数
void check() {
	int Day[10] = {0}, day = -1; // 0 表示可能 1 表示不可能
	int Peo[N] = {0}, peo = -1;
	for (saying i : P) {
		int I = i.yes ^ (1 - trust[i.say]);
		if (i.days != -1) { // 证言关于星期
			if (I == 1) {
				if (Day[i.days]) return; 
				if (day != -1 && day != i.days) return; 
				if (day == -1) day = i.days;
				for (int i = 1; i <= 7; i++) if (i != day) Day[i] = 1;
			} else {
				if (day == i.days) return;
				Day[i.days] = 1;
				int cnt = 0, x;
				for (int i = 1; i <= 7; i++) if (Day[i] == 0) cnt++, x = i;
				if (cnt == 1) day = x;
			}
		}
		else {
			if (I == 1) {
				if (Peo[i.people]) return; 
				if (peo != -1 && peo != i.people) return; 
				if (peo == -1) peo = i.people;
				for (int i = 1; i <= m; i++) if (i != peo) Peo[i] = 1;
			} else {
				if (peo == i.people) return;
				Peo[i.people] = 1;
				int cnt = 0, x;
				for (int i = 1; i <= m; i++) if (Peo[i] == 0) cnt++, x = i;
				if (cnt == 1) peo = x;
			}
		}
	}
	if (peo != -1) {
		crime.insert(peo);
	} else if (m == 1) {
		crime.insert(1);
	} else if (peo == -1) {
		for (int i = 1; i <= m; i++) if (Peo[i] == 0) crime.insert(i);
	}
}
void dfs (int i, int x) { // 现在 id; 已经不诚信的人数
	if (x > n) return;
	if (i == m + 1) { // 枚举完了
		if (x == n) check();
		return;
	} 
	trust[i] = true;
	dfs (i + 1, x);
	trust[i] = false;
	dfs (i + 1, x + 1);
}
int main() {
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> m >> n >> p;
    for (int i = 1; i <= m; i++) {
    	cin >> s[i];
    	id[s[i]] = i;
    }
    for (int i = 1; i <= p; i++) {
    	string s, t, o;
    	cin >> s >> t; getchar();
    	getline(cin, o);
    	s.pop_back();
    	while(o.back()=='\r' || o.back()=='\n'){
    		o.pop_back();
		}
    	if (t == "I" && o == "am not guilty.") { // 我不是罪犯
    		P.push_back({id[s], id[s], 0, -1});
    	} else if (t == "I" && o == "am guilty.") { // 我是罪犯
    		P.push_back({id[s], id[s], 1, -1});
    	} else if (t == "Today") {
    		o = o.substr(3);
    		o.pop_back();
    		if (Days[o]) 
    			P.push_back({id[s], -1, 1, Days[o]});
    	} else if (o == "is guilty."){
    		if (id[t]) 
    			P.push_back({id[s], id[t], 1, -1});
    	} else if (o == "is not guilty.") {
    		if (id[t]) 
    			P.push_back({id[s], id[t], 0, -1});
    	}
    }
    dfs (1, 0);
    if (crime.size() == 0) puts("Impossible");
    else if (crime.size() > 1) puts("Cannot Determine");
    else cout << s[*crime.begin()];
    return 0;
}