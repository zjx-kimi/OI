#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e7 + 9;
const int mod = 998244353;
int n, res = 1;
int arr[N];
map <int, int> cnt, num;
vector <int> v;

int sqr(int x) {
	int y=sqrt(x);
	return y*y==x?y:0;
}

int cbr(int l,int r,int v){
	if(l==r)return (l*l*l==v?l:0);
	int m=l+r>>1;
	return m*m*m>=v?cbr(l,m,v):cbr(m+1,r,v);
}
bool check(int x) {
	int y=sqr(x);
	if(y){
		int z=sqr(y);
		z?cnt[z]+=4:cnt[y]+=2;
		return 1;
	}
	else{
		y=cbr(1,2e6,x);
		if(y) {cnt[y]+=3; return 1;}
	} return 0;
}

int gcd (int x, int y) {return y ? gcd (y, x % y): x; }
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
    	if (!check(arr[i]))
    		if(!num[arr[i]]) 
    			v.push_back(arr[i]), num[arr[i]]++;
    		else num[arr[i]]++;
    }
    for (int i = 0; i < v.size(); i++) {
    	for (int j = i + 1; j < v.size(); j++) {
    		int x = gcd(v[i], v[j]);
    		if (x > 1 && cnt.find(x) == cnt.end()) cnt[x] = 0; // 加入
    	}
    }
    for (int i : v) {
    	int d = num[i] + 1;
    	int c = 2;
    	for (auto j : cnt) {
    		if (i % j.first == 0){
	    		cnt[j.first] += d - 1;
	    		i /= j.first, c--;
	    	}
    	}
    	(res *= ((int)pow(d, c) % mod)) %= mod;
    }
    for (auto i : cnt) (res *= (1 + i.second)) %= mod;
    cout << res << '\n';
    return 0;
}