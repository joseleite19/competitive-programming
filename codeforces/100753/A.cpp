#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

vector<pair<int, int> > g[20004];
vector<int> dist;

pair<int,int> place[20];

int mat[20][20];
int dp[20][1 << 18][2];
int n, p, m, tot, t;

void dijkstra(int source){
	dist.assign(n+1, oo);
	priority_queue<pair<int,int> > q;
	
	dist[source] = 0;
	q.push(mp(0, source));

	while(!q.empty()){
		int d = -q.top().ff, u = q.top().ss; q.pop();

		for(int i = 0; i < g[u].size(); i++){
			pair<int,int> v = g[u][i];
			if(v.ss + d < dist[v.ff]){
				dist[v.ff] = v.ss + d;
				q.push(mp(-dist[v.ff], v.ff));
			}
		}
	}
}


int f(int pos, int mask, int taxi){
	int limit, newb;
	int & ans = dp[pos][mask][taxi];
	
	if(ans != -1) return ans;

	ans = oo;
	if(!mask){
		ans = min(ans, mat[pos][p]);
		if(taxi) ans = min(ans, t);
		return ans;
	}

	for(int i = 0; i < p; i++){
		if(mask & (1 << i)){
			newb = mask & ~(1 << i);
			ans = min(ans, mat[pos][i] + f(i, newb, taxi) + place[i].ss);
			if(taxi) ans = min(ans, t + f(i, newb, 0) + + place[i].ss);
		}
	}

	return ans;
}


int main(){

	scanf("%d %d %d %d %d", &n, &p, &m, &tot, &t);

	for(int i = 0; i < p; i++)
		scanf("%d %d", &place[i].ff, &place[i].ss);

	place[p] = mp(0, 0);

	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(mp(b, c));
		g[b].push_back(mp(a, c));
	}
	for(int i = 0; i <= p; i++){
		dijkstra(place[i].ff);
		for(int j = 0; j <= p; j++)
			mat[i][j] = dist[ place[j].ff ];
	}

	memset(dp, -1, sizeof dp);

	int tmp1 = f(p, (1 << p)-1, 0);
	int tmp2 = f(p, (1 << p)-1, 1);

	// printf("%d %d\n", tmp1, tmp2);

	if(tmp1 <= tot) printf("possible without taxi\n");
	else if(tmp2 <= tot) printf("possible with taxi\n");
	else printf("impossible\n");

	return 0;
}