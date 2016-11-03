#include <bits/stdc++.h>

using namespace std;

char s[200];
int v[200];
long long dp[105][105][11][2];
int n;

#define MOD (1000000007)

vector<vector<int> > g;
map< pair<int, pair<int, pair<int, int> > >, int > mapv;
int ptr;

long long exp(long long b){
	int e = MOD - 2;
	long long ans = 1;
	while(e){
		if(e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}

long long f(int i, int qntp, int sum, bool ja){
	long long & ret = dp[i][qntp][sum][ja];
	int qntm = n/2 - (i - (n - n/2 - qntp));
	if(ret != -1) return ret;
	ret = 0;
	if(i == n){
		if(sum == 0 && qntp == 0 && qntm == 0 && ja)
			return ret = 1;
		return ret = 0;
	}

	if(v[i] == 0){
		if(qntp){
			ret = max(ret, f(i+1, qntp-1, sum, ja));
			if(f(i+1, qntp-1, sum, ja)){
				pair<int, pair<int, pair<int, int> > > s, t;
				s = mp(i, qntp, sum, ja);
				t = mp(i+1, qntp-1, sum, ja);
				if(mapv.find(s) == mapv.end()) mapv[ ptr++ ] = s;
				if(mapv.find(t) == mapv.end()) mapv[ ptr++ ] = t;
				g[ mapv[s] ].push_back(t);
			}
		}
		if(qntm){
			ret = max(ret, f(i+1, qntp  , sum, ja));
		}
	}
	else{
		if(qntp) ret = (ret + (f(i+1, qntp-1, (sum+v[i]+11)%11,  1))) % MOD;
		if(qntm) ret = (ret + (f(i+1, qntp  , (sum-v[i]+11)%11, ja))) % MOD;
	}

	return ret;
}

long long fat[105];
int qnt[10];
int main(){
	fat[0] = 1;

	for(int i = 1; i < 105; i++)
		fat[i] = (i*fat[i-1])%MOD;

	while(scanf("%s", s) == 1){
		g.assign(300000, vector<int>());
		mapv.clear();
		ptr = 1;
		memset(qnt, 0, sizeof qnt);

		n = strlen(s);
		for(int i = 0; i < n; i++){
			v[i] = s[i]-'0';
			qnt[ v[i] ]++;
		}
		int n1, n2;
		n2 = n/2;
		n1 = n - n2;
		long long tmp = (fat[n1]*fat[n2])%MOD;
		
		for(int i = 0; i < 10; i++)
			tmp = (tmp*exp(fat[ qnt[i] ]))%MOD;

		memset(dp, -1, sizeof dp);
		printf("%lld\n", (tmp*f(0, n1, 0, 0))%MOD);
	}

	return 0;
}