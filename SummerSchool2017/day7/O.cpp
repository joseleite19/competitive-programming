#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

long long dp[50][10][50000];
bool mark[50][10][50000];

long long G[55][55];

long long C(int n, int k){
	if(n == k || k == 0 || n == 0) return 1;
	if(G[n][k] != -1) return G[n][k];
	return G[n][k] = C(n-1, k) + C(n-1, k-1);
}

int n;
int v[51];


long long f(int ondeto, int qntfalta, int qnt_falta_maior){

	if(qntfalta == 0){
		if(qnt_falta_maior > 0) return 0;
		if(qnt_falta_maior == 0) return 0;
		return 1;
	}

	if(qnt_falta_maior < 0){
		if(qntfalta > n - ondeto) return 0;

		return C(n-ondeto, qntfalta);
	}

	if(ondeto == n){
		return 0;
	}

	if(mark[ondeto][qntfalta][qnt_falta_maior]) return dp[ondeto][qntfalta][qnt_falta_maior];
	mark[ondeto][qntfalta][qnt_falta_maior] = 1;
	long long &ans = dp[ondeto][qntfalta][qnt_falta_maior];

	ans = 0;

	ans += f(ondeto+1, qntfalta-1, qnt_falta_maior - v[ondeto]);
	ans += f(ondeto+1, qntfalta, qnt_falta_maior);

	return ans;
}

int main(){
	memset(G, -1, sizeof G);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	sort(v, v+n);
	reverse(v, v+n);
	int k;

	scanf("%d", &k);

	long long ans = 0;

	for(int i = 0; i < n; i++){
		ans += f(i+1, k-1, v[i]);
		// printf("%lld\n", ans);
	}

	printf("%lld\n", ans);





	return 0;
}