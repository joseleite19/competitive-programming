#include <bits/stdc++.h>

#define oo (1000000000000000000)

using namespace std;

string P[1003], T;
int power[1003];

int b[10004];

void kmpPreprocess(int id) {
	int i = 0, j = -1; b[0] = -1;
	while (i < P[id].size()) {
		while (j >= 0 && P[id][i] != P[id][j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

vector<vector<int> > occ;

void kmpSearch(int id){
	kmpPreprocess(id);
	int i = 0, j = 0;
	while (i < T.size()) {
		while (j >= 0 && T[i] != P[id][j]) j = b[j]; // different, reset j using b
		i++; j++;
		if (j == P[id].size()) {
			// i - j << no indice (i-j) foi achado ocorrencia da string id
			occ[i-j].push_back(id);
			j = b[j];
		}
	}
}

char tmps[10004];

int c;

long long dp[1003];
int mark[1003], pass = 0;

long long f(int i){
	if(i == T.size()) return 0;
	if(mark[i] == pass) return dp[i];
	mark[i] = pass;

	dp[i] = -oo;
	for(int j = 0; j < occ[i].size(); j++){
		int d = occ[i][j];
		dp[i] = max(dp[i], f(i+P[d].size()) + power[d]);
	}
	return dp[i];
}

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf(" %s", tmps);
		T = tmps;
		scanf("%d", &c);

		occ.assign(T.size(), vector<int>());
		for(int i = 0; i < c; i++){
			scanf(" %s %d", tmps, power+i);
			P[i] = tmps;
			memset(b, 0, sizeof b);
			kmpSearch(i);
		}

		vector<int> resp;
		pass++;

		for(int i = 0; i < T.size(); ){
			int next_id = T.size()+10, put = 0;
			for(int j = 0; j < occ[i].size(); j++){
				int d = occ[i][j];
				if(f(i+P[d].size()) + power[d] == f(i)){
					if(i+P[d].size() < next_id){
						next_id = i+P[d].size();
						put = d;
					}
				}
			}
			resp.push_back(put);
			i = next_id;
		}

		printf("Inscricao #%d:\n", tc);
		printf("%lld\n", f(0));
		printf("%s", P[ resp[0] ].c_str());
		for(int i = 1; i < resp.size(); i++)
			printf(" %s", P[ resp[i] ].c_str());
		printf("\n");
	}

	return 0;
}