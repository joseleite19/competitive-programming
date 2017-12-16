#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
long long dp[100005][2], v[100005];
int mark[100005][2];

long long f(int i, int j){
	if(i == n){
		return j ? 0 : -1000000000000000000;
	}
	if(mark[i][j]) return dp[i][j];
	mark[i][j] = 1;

	return dp[i][j] = max(v[i] + f(i+1, (j+v[i])&1), f(i+1, j));
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	printf("%lld\n", f(0, 0));


	return 0;
}