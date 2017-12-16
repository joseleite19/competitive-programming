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
const int N = 10004;
const int E = 250004;
const int M = N/2;

vector<int> g[N]; // <vx, <edge weight, id reverse edge>>

int ne = 0;
struct EEE{
    int from, to;
    ll cap;
    inline void set(int f_, int t_, ll c_){ from = f_, to = t_; cap = c_; }
} Edge[E];


int lvl[N], vis[N], pass, source, target, p[N],  px[N];

vector<vector<int> > ans;

void push(int s){
    vector<int> v;
    while(s != source){
        if(s < M) v.pb(s);
        s = p[s];
    }
    reverse(all(v));
    ans.eb(move(v));
}

ll run(int s, ll minE){
	if(s == target) return minE;

	ll ans = 0;

	for(; px[s] < g[s].size(); px[s]++){
        int e = g[s][ px[s] ];
		auto &v = Edge[e], &rev = Edge[e^1];
		if(lvl[v.to] != lvl[s]+1 || !v.cap) continue;
        ll tmp = run(v.to, min(minE, v.cap));
		v.cap -= tmp, rev.cap += tmp;
		ans += tmp, minE -= tmp;
		if(minE == 0) break;
	}
	return ans;
}

int bfs(){

	queue<int> q;
	q.push(source);
	lvl[source] = 1;
	vis[source] = ++pass;

	while(!q.empty()){
		int u = q.front(); q.pop();
		px[u] = 0;

		for(int e : g[u]){
            auto v = Edge[e];
			if(v.cap <= 0 || vis[v.to] == pass) continue;
			vis[v.to] = pass;
			lvl[v.to] = lvl[u]+1;
			q.push(v.to);
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
    Edge[ne].set(u, v, c);
    g[u].eb(ne++);
    Edge[ne].set(v, u, 0);
    g[v].eb(ne++);
}

char s[1000*N];

void build(int s){
    if(s == target){ push(s); return; }
    for(int e : g[s]){
        auto x = Edge[e];
        if(x.cap || e % 2 == 1) continue;
        p[x.to] = s;
        build(x.to);
    }
}

int main(){
    int n, m, k;
    source = 0, target = 2+M;

    for(int tc = 1; scanf("%d %d", &k, &n) == 2 && n+k; tc++){
        ne = 0;
        ans.clear();
        forn(i, N) g[i].clear();

        map<pair<int, int>, int> cnt;
        for1(i, n){
            scanf(" %[^\n]", s);
            stringstream ss(s);
            int x;
            while(ss >> x) addEdge(i, x+M, 1);
        }
        for(int i = 3; i <= n; i++) addEdge(i+M, i, 1);
        addEdge(0, 1, k);
        
        printf("Case %d:\n", tc);
        if(flow() < k) printf("Impossible\n");
        else{
            p[0] = 0;
            build(0);
            forn(i, ans.size()){
                for(int x : ans[i]) printf("%d ", x);
                printf("2\n");
            }
        }
        printf("\n");
    }



    return 0;
}
