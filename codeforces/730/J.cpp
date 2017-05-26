#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair
#define oo 1000006

using namespace std;

int n, a[102], b[102], k;

pair<int, int> dp[102][10004];
int mark[102][10004];
int dp2[102][102];
int mark2[102][102];

pair<int, int> f(int i, int w){
	if(mark[i][w]) return dp[i][w];
	mark[i][w] = 1;

	if(i == n){
		if(w == 0) return dp[i][w] = mp(0, 0);
		return dp[i][w] = mp(oo, oo);
	}
	pair<int, int> tmp = f(i+1, max(0, w-b[i]));
	tmp.ff++;
	pair<int, int> tmp1 = f(i+1, w);
	tmp1.ss += a[i];
	
	return dp[i][w] = min(tmp, tmp1);
}

int f2(int i, int k){
	if(mark2[i][k]) return dp2[i][k];
	mark2[i][k] = 1;

	if(i == n){
		if(k == 0) return dp2[i][k] = 0;
		return dp2[i][k] = oo;
	}

	if(k == 0) dp2[i][k] = f2(i+1, k) + a[i];

	return dp2[i][k] = min(f2(i+1, k-1), f2(i+1, k) + a[i]);
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", a+i);
	for(int i = 0; i < n; i++)
		scanf("%d", b+i);

	int sum = 0;

	for(int i = 0; i < n; i++)
		sum += a[i];

	pair<int, int> tmp = f(0, sum);
	printf("%d %d\n", tmp.ff, tmp.ss);

	// int k = f(0, sum);

	// printf("%d\n", f2(0, k));

	return 0;
}