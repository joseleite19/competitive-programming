#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

vector<int> g[1 << 21];
int n, k;

int dist[1 << 21];

int can(int x){
	return __builtin_popcount(x) <= k;
}

int p[1 << 21];

int last;

int mx = 0;
int cnt = 0;
void dfs(int bit){
	// printf("$%d %d\n", bit, p[bit]);
	// mx = max(mx, dist[bit]);
	if(__builtin_popcount(bit) > cnt - dist[bit]+1) return;
	if(dist[bit] > mx){
		// p[bit] = pai;
		mx = dist[bit];
		last = bit;
	}


	for(int i = 0; i < (int)g[bit].size(); i++){
		int nb = g[bit][i];
		if(!dist[nb]){
			dist[nb] = dist[bit]+1;
			p[nb] = bit;
			dfs(nb);
		}
	}
}

void volta(int bit){
	if(p[bit]) volta(p[bit]);
	// printf("asd\n");
	int j = 0;
	for(j = 0; j < n; j++){
		int a = (1 << j) & bit;
		int b = (1 << j) & p[bit];

		if(a != b) break;
	}
	// printf("\n%d->%d : %d\n", p[bit], bit, j);
	if((p[bit] | (1 << j)) == bit){
		printf("+%d", j+1);
	}
	else if(p[bit] == (bit | (1 << j))){
		printf("-%d", j+1);
	}
	else if(p[bit] & (1 << j)){
		printf("++%d", j+1);
	}
	else printf("--%d", j+1);
}

int main(){

	scanf("%d %d", &n, &k);

	for(int bit = 0; bit < (1 << n); bit++){
		if(!can(bit)) continue;
		cnt++;

		int nb;
		for(int j = 0; j < n; j++){
			if(bit & (1 << j)){
				nb = bit - (1 << j);
				g[bit].push_back(nb);
				
				if(j < n-1){
					nb = bit - (1 << j) + (1 << (j+1));
					g[bit].push_back(nb);
 				}
 				if(j > 0){
					nb = bit - (1 << j) + (1 << (j-1));
					g[bit].push_back(nb);
 				}
			}
			else{
				nb = bit | (1 << j);
				if(!can(nb)) continue;
				g[bit].push_back(nb);
			}
		}
	}
	// printf("asd\n");

	// queue<int> q;

	// q.push(0);
	// dist[0] = 1;


	// while(!q.empty()){
	// 	int bit = q.front(); q.pop();
	// 	mx = max(mx, dist[bit]);

	// }

	dist[0] = 1;
	dfs(0);
	// printf("%d %d\n", mx, cnt);

	if(mx != cnt){
		printf("0\n");
		return 0;
	}

	// for(int i = 0; i < 8; i++)
	// 	printf("%d %d\n", i, p[i]);
	// printf("%d\n", last);
	// printf("YAY\n");
	volta(last);
	for(int j = 0; j < n; j++)
		if(last & (1 << j))
			printf("-%d", j+1);
	printf("\n");



	return 0;
}