#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

double dp[1 << 20];
int m, p[20], a[20], n[20], x[20][20], y[20][20];

double f(int bit){
	if(dp[bit] != -1) return dp[bit];
	if(bit == 0) return 0;
	double & ret = dp[bit];

	double vet[20];

	for(int i = 0; i < m; i++)
		vet[i] = 1;

	for(int i = 0; i < m; i++)
		if((1 << i) & bit)
			for(int j = 0; j < n[i]; j++)
				vet[ x[i][j] ] *= (100 - y[i][j]) / 100.0;

	ret = 1e50;
	for(int i = 0; i < m; i++)
		if((1 << i) & bit)
			ret = min(ret, f(bit & ~(1 << i)) + p[i]*vet[i]);

	return dp[bit] = ret;
}

int main(){
	int area;
	double ans;

	while(scanf("%d", &m) == 1 && m){

		for(int i = 0; i < m; i++){
			scanf("%d %d %d", p+i, a+i, n+i);
			for(int j = 0; j < n[i]; j++)
				scanf("%d %d", &x[i][j], &y[i][j]), x[i][j]--;
		}

		for(int i = 0; i < (1 << m); i++)
			dp[i] = -1;

		ans = 1e50;

		for(int bit = 1; bit < (1 << m); bit++){
			area = 0;
			for(int i = 0; i < m; i++)
				if(bit & (1 << i))
					area += a[i];

			ans = min(ans, f(bit) / area);
		}
		printf("%.4lf\n", ans);
	}	

	return 0;
}