#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
double f[305][305][305];
int a[4],n; 
int main(){
	cin >> n;
	for(int i=1,x;i<=n;++i){
		cin >> x;
		a[x]++;
	}	
	for (int k = 0; k <= n; ++k){
		for (int j = 0; j <= n; ++j){
			for(int i = 0; i <= n ;++i){
				if(i||j||k){
					if(i) f[i][j][k] += f[i-1][j][k] *  i / (i + j + k);
        			if(j) f[i][j][k] += f[i+1][j-1][k] * j / (i + j + k);
    	    		if(k) f[i][j][k] += f[i][j+1][k-1] * k / (i + j + k);
	        		f[i][j][k] += (double)n / (i + j + k);
         		}
			}
		}
	}
	printf("%.15lf\n",f[a[1]][a[2]][a[3]]);
	return 0;
}