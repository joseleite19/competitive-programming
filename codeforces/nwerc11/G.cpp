#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int vert[105];
map<string, int> tab;
pair<int,int> pos[105];
bool tao[105];
vector<int> G[105];
int dag, indg[105], dp[105];
stack<int> S;
char nm[105][30];
int vis[105];

void dfs(int v){
	vis[v] = 1;

	for(int x : G[v])
		if(!vis[x]) dfs(x);

	S.push(v);
}

long long dist(int i, int j){
	long long aux = pos[i].ff-pos[j].ff, aux2 = pos[i].ss-pos[j].ss;
	return (aux*aux + aux2*aux2);
}

void ehdag(int v){
	vis[v] = 1;
	
	for(int x : G[v]){
		if(vis[x] == 1) dag = 0;
		else if(vis[x] == 0) ehdag(x);
	}
	vis[v] = 2;
}

int maior(int v){
	if(G[v].empty()) return 1;
	if(dp[v] != -1) return dp[v];

	int ret = 0;
	for(int x : G[v]){
		ret = max(ret, maior(x)+1);
	}

	return dp[v] = ret;
}

int main(){
	int t,n,m,x,y;
	char s[25], s1[25], s2[25], s3[25];

	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n,&m);
		tab.clear();
		for(int i = 0; i < 105; i++) G[i].clear();

		memset(tao, 0, sizeof tao);
		memset(indg, 0, sizeof indg);

		for(int i = 0; i < n; i++){
			scanf(" %s %d %d", s, &x, &y);
			strcpy(nm[i], s);
			tab[s] = i;
			pos[i] = mp(x,y);
			G[i].clear();
		}

		bool shazan = 0;
		while(m--){
			scanf(" %s heard %s firing before %s", s1,s2,s3);
			tao[tab[s2]] = tao[tab[s3]] = 1;
			if(dist(tab[s1], tab[s2]) >= dist(tab[s1], tab[s3])){
				G[tab[s2]].push_back(tab[s3]);
				// if(!strcmp(s1, s3)) shazan = 1;
				indg[tab[s3]]++;
			}
		}

		dag = 1;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; i++){
			if(tao[i] && vis[i] == 0)
				ehdag(i);
		}

		if(!dag || shazan){
			printf("IMPOSSIBLE\n");
			continue;
		}

		memset(dp, -1, sizeof dp);
		int ans = 0, atuais = 0;
		for(int i = 0; i < n; i++){
			if(tao[i]) atuais++;
			// if(tao[i] && indg[i] == 0){
				ans = max(ans, maior(i));
			// }
		}
		// printf("dsa %d %d\n", atuais, ans);

		if(ans != atuais){
			printf("UNKNOWN\n");
			continue;
		}

		memset(vis,0,sizeof vis);
		for(int i = 0; i < n; i++){
			if(tao[i] && indg[i] == 0){
				dfs(i);
				break;
			}
		}

		bool first = 1;
		while(!S.empty()){
			if(first){
				printf("%s", nm[S.top()]);
				first = 0;
			}
			else{
				printf(" %s", nm[S.top()]);
			}
			S.pop();
		}

		printf("\n");
	}

	return 0;
}