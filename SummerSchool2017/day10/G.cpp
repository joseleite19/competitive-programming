#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define oo 1000000000

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}


long long dp[606][606][55];
bool mark[606][606][55];

long long mat[606][606];
long long sum[606];
long long sum2d[606][606];

int n, k;

long long f(int a, int b, int c, int s){
	// printf("%d %d %d %d\n",a,b,c,s);
	// if(s < 0) printf("sd");
	if(s < 0) return -oo;
	if(a == n-1) return 0;
	if(c == k) return 0;

	if(mark[a][b][c]) return dp[a][b][c];
	mark[a][b][c] = 1;

	return dp[a][b][c] = max(f(a+1, a, c+1, sum[a+1]) + s, f(a+1, b, c, s + sum[a+1] - sum2d[a][a] + sum2d[b][a]));
}


int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			scanf("%lld", &mat[i][j]);
			sum[i] += mat[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sum2d[i][j] += (i > 0 ? sum2d[i-1][j] : 0) + mat[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%lld ", sum2d[i][j]);
			/* code */
		}
		printf("\n");
		/* code */
	}

	// i, j
	// tmp = 0
	// for(q = i; q < n; q++)
	// 	tmp += mat[q][j];

	printf("%lld\n", f(0, 0, 0, sum[0]));


	return 0;
}