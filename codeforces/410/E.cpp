#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<int> g[500005];
int color[500005];
int c;

int dfs(int u){

	for(int v : g[u])
		dfs(v);
	color[u] = c++;
}

int main(){
	int n, x;
	int last = -1, source = -1;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(x == -1){
			if(last == -1) source = last = i;
			else{
				g[last].push_back(i);
				last = i;
			}
		}
		else{
			g[x].push_back(i);
		}
	}

	c = 1;

	dfs(source);

	for(int i = 1; i <= n; i++)
		printf("%d ", color[i]);
	printf("\n");



	return 0;
}