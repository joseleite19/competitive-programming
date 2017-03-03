#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define MOD (1000000009)

using namespace std;

void file(){
	freopen("settling.in", "r", stdin);
	freopen("settling.out", "w", stdout);
}

vector<int> adj[205];
int vis[205];

long long mat[205][205];

int main(){
    // file();
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++){
		int sai,vai;
		scanf("%d %d",&sai,&vai);
		adj[sai].pb(vai);
		mat[sai][vai] = 1;
	}


	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				mat[i][j] += (mat[i][k]*mat[k][j]) % MOD;
				mat[i][j] = (mat[i][j] + MOD) % MOD;
			}
		}
	}

	for(int i = 1; i <= n; i++)
		mat[i][i] = 1;

	long long int qtd = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			qtd += mat[i][j] != 0;
	int k;
	scanf("%d", &k);

	printf("%lld\n", qtd);
	while(k--){
		char c;
		int u,v;
		qtd = 0;
		scanf(" %c %d %d",&c,&u,&v);
		if(c == '-'){
			qtd = 0;

			for(int i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++){
					mat[i][j] -= (mat[i][u]*mat[v][j]) % MOD;
					mat[i][j] = (mat[i][j] + MOD) % MOD;
					qtd += mat[i][j] != 0;
				}
			}

			printf("%lld\n",qtd);
		}
		else if(c == '+'){
			qtd = 0;

			for(int i = 1; i <= n; i++){
				for(int j = i+1; j <= n; j++){
					mat[i][j] += (mat[i][u]*mat[v][j]) % MOD;
					mat[i][j] = (mat[i][j] + MOD) % MOD;
					qtd += mat[i][j] != 0;
				}
			}

			printf("%lld\n",qtd);
		}
		else if(c == '?'){
			printf("%s\n", mat[u][v] ? "YES" : "NO");
		}
	}
	return 0;
}