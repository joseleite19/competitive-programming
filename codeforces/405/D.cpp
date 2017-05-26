#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)
#define oo (1000000000000000000)

using namespace std;

int n, k;

vector<int> g[200005];

long long ans;


vector<long long> dfs(int u, int p){

	vector<long long> ret(k+1, 0);
	ret[0] = 1;
	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i];
		if(v == p) continue;
		vector<long long> tmp = dfs(v, u);

		if(u == 3) printf("|%lld %lld\n", ans, tmp[k]);
		for(int j = 0; j < k; j++){
			for(int q = 0; q < k; q++){
				if(u == 3) printf("%d %d %lld %lld\n", q, j, ret[q], tmp[j]);
				if(!ret[q] || !tmp[j]) continue;
				if(q + j == 0){
					ans += (ret[q]*tmp[k] + tmp[j]*ret[k]);
				}
				else if(q + j <= k){
					ans += (ret[q]*tmp[k] + tmp[j]*ret[k] + ret[q]*tmp[j]);
					// ans += (ret[q]+1) * tmp[j];
				}
				else{
					ans += (ret[q]*tmp[k] + tmp[j]*ret[k] + 2*ret[q]*tmp[j]);
					// ans += (ret[q]+2) * tmp[j];
				}
			}
		}
		// ans += tmp[k];
		for(int j = 0; j <= k; j++)
			ret[j] += tmp[j];
	}
	long long tmp = ret[0];
	for(int i = 1; i < k; i++)
		swap(tmp, ret[i]);
	ret[0] = tmp;
	ret[k] += tmp;
	printf("%d %lld\n", u+1, ans);
	return ret;
}


int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n-1; i++){
		int u, v;
		scanf("%d %d", &u, &v); u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0, 0);

	printf("%lld\n", ans);

	return 0;
}