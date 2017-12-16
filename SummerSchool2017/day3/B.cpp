#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

using namespace std;

int n, k;

long long v[100005];

long long w[100005];
long long inv[100005];

long long pot(long long b, long long e){
	long long ans = 1;
	while(e){
		if(e & 1) ans = (ans*b) % MOD;
		b = (b*b) % MOD;
		e >>= 1;
	}
	return ans;
}

vector<pair<long long, int> > r[20];

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	long long mx = 0;
	for(int i = 0; i < n; i++)
		mx = max(mx, v[i]+1);

	w[0] = 1;

	for(int i = 1; i < n; i++)
		w[i] = (w[i-1] * mx) % MOD;

	inv[0] = 1;
	inv[1] = pot(mx, MOD-2);

	for(int i = 2; i < n; i++)
		inv[i] = (inv[i-1] * inv[1]) % MOD;

	for(int i = 0; i < n; i++){
		int cnt = 0;
		long long tmp = v[i];
		while(tmp > 0){
			tmp /= 10;
			cnt++;
		}
		r[cnt].push_back(mp(v[i], i));
		// printf("%d\n", cnt);
	}

	for(int i = 0; i < 20; i++){
		printf("%d:", i);
		for(int j = 0; j < r[i].size(); j++)
			printf(" %lld", r[i][j].ff);
		printf("\n");
	}


	while(k--){
		
	}








	return 0;
}