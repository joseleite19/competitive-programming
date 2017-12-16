#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000LL;
const int N = 100005;

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

int c[N];

int main(){
    int n, m, k;

    for(int tc = 1; scanf("%d %d %d", &n, &m, &k) == 3; tc++){
        source = n+m, target = n+m+1;
        forn(i, n) scanf("%d", c+i), addEdge(m+i, target, c[i]);
        forn(i, m) addEdge(source, i, 1);
        
        forn(i, k){
            int a, b;
            scanf("%d %d", &a, &b); a--, b--;
            addEdge(b, m+a, 1);
        }

        printf("Instancia %d\n%lld\n\n", tc, flow());

        forn(i, n+m+2) g[i].clear();
    }



    return 0;
}
