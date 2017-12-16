#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

typedef long long ll;

const int N = 10004;

vector<pair<int, pair<ll, int> > > g[N]; // <vx, <edge weight, id reverse edge>>

int lvl[N], vis[N], source, target;

size_t px[N];

ll run(int s, ll minE){
	if(s == target) return minE;

	ll ans = 0;

	for(; px[s] < g[s].size(); px[s]++){
		auto &v = g[s][ px[s] ];
		if(lvl[v.ff] != lvl[s]+1 || !v.ss.ff) continue;
		ll tmp = run(v.ff, min(minE, v.ss.ff));
		v.ss.ff -= tmp;
		g[v.ff][v.ss.ss].ss.ff += tmp;
		ans += tmp;
		minE -= tmp;
		if(minE == 0) break;
	}
	return ans;
}

int pass;
int bfs(){

	queue<int> q;
	q.push(source);
	lvl[source] = 1;
	vis[source] = ++pass;

	while(!q.empty()){
		int u = q.front(); q.pop();
		px[u] = 0;

		for(auto v : g[u]){
			if(v.ss.ff <= 0 || vis[v.ff] == pass) continue;
			vis[v.ff] = pass;
			lvl[v.ff] = lvl[u]+1;
			q.push(v.ff);
		}
	}

	return vis[target] == pass;
}

ll flow(){

	ll ans = 0;
	while(bfs())
		ans += run(source, oo);
	return ans;
}

void addEdge(int u, int v, ll c){
	pair<int, pair<ll, int> > a, b;
	a = {u, {0, g[u].size()}};
	b = {v, {c, g[v].size()}};
	g[u].push_back(b);
	g[v].push_back(a);
}

bool isa[N], isb[N];
int pie[N];

int getu(int x){
    if(isa[x] && !isb[x]) return source;
    if(!isa[x] && isb[x]) return target;
    return x;
}

int main(){
    target = N-1;
    source = N-2;
    int k, n, a, b;

    scanf("%d %d %d %d", &k, &n, &a, &b);

    for(int i = 0; i < a; i++){
        int x;
        scanf("%d", &x);
        isa[x] = 1;
    }

    for(int i = 0; i < b; i++){
        int x;
        scanf("%d", &x);
        isb[x] = 1;
    }

    for(int i = 1; i <= n; i++)
        scanf("%d", pie+i);
	
    ll ans = 0;
    for(int i = 1; i < n; i++){
        int x;
        scanf("%d", &x);
        ans += x;
        int u = getu(pie[i]);
        int v = getu(pie[i+1]);
        addEdge(u, v, x);
        addEdge(v, u, x);
    }

    printf("%lld\n", ans - flow());
    
    return 0;
}
