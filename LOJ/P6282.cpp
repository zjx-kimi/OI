#include<bits/stdc++.h>
using namespace std;
int n, d, nn;
int a[200005];
vector<int> v[1005];

void mer(){ //把所有元素还原到 a 数组中
	n = 0;
	for ( int i = 1; i <= d + 1; ++i ){
		if ( v[i].empty() ) break; 
		for ( int j = 0; j < v[i].size(); ++j ) a[++n] = v[i][j];
		v[i].clear();
	}
}

void div(){ //把 a 数组元素分配到各个块中
	d = sqrt(n);
	for ( int i = 1; i <= n; ++i ) v[( i - 1 ) / d + 1].push_back(a[i]);
}

int Get( int wh ){
	for ( int i = 1; i <= d + 1; ++i ){
		if ( wh > v[i].size() ) wh -= v[i].size();
		else return v[i][wh - 1]; 
	}
}

void Ins( int wh, int x ){
	for ( int i = 1; i <= d + 1; ++i ){
		if ( wh > v[i].size() ) wh -= v[i].size();
		else{
			v[i].insert( v[i].begin() + wh - 1, x ); //插入
			if ( v[i].size() > 10 * d ) mer(), div(); //重排
			return;
		}
	}
}

int main(){
	scanf( "%d", &n );
	for ( int i = 1; i <= n; ++i ) scanf( "%d", &a[i] );
	div();
	nn = n;
	for ( int i = 1; i <= nn; ++i ){
		int opt, l, r, c;
		scanf( "%d%d%d%d", &opt, &l, &r, &c );
		if ( opt ) printf( "%d\n", Get(r) );
		else Ins( l, r );
	}
	return 0;
}