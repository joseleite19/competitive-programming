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
const int M = N/2;

//vector<pair<int, pair<ll, pair<int, int> > > > g[N]; // <vx, <edge weight, id reverse edge>>
vector<tuple<int, ll, int, int> > g[N]; // <vx, <edge weight, id reverse edge>>

int lvl[N], vis[N], source, target, p[N];

size_t px[N];

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
		auto &v = g[s][ px[s] ];
		if(lvl[get<0>(v)] != lvl[s]+1 || !get<1>(v)) continue;
        ll tmp = run(get<0>(v), min(minE, get<1>(v)));
		get<1>(v) -= tmp;
		get<1>(g[get<0>(v)][get<3>(v)]) += tmp;
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
			if(get<1>(v) <= 0 || vis[get<0>(v)] == pass) continue;
			vis[get<0>(v)] = pass;
			lvl[get<0>(v)] = lvl[u]+1;
			q.push(get<0>(v));
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
	tuple<int, ll, int, int> a, b;
	a = mt(u, 0, 0, g[u].size());
	b = mt(v, c, 1, g[v].size());
	g[u].eb(b), g[v].eb(a);
}

char s[1000*N];

void build(int s){
    if(s == target){ push(s); return; }
    for(auto x : g[s]){
        if(get<1>(x) || !get<2>(x)) continue;
        p[get<0>(x)] = s;
        build(get<0>(x));
    }
}

int main(){
    int n, m, k;
    source = 0, target = 2+M;

    for(int tc = 1; scanf("%d %d", &k, &n) == 2 && n+k; tc++){
        ans.clear();
        forn(i, N) g[i].clear();

        int a, b; char c;
        map<pair<int, int>, int> cnt;
        for1(i, n){
            scanf(" %[^\n]", s);
            stringstream ss(s);
            int x;
            while(ss >> x) if(0 < x && x <= n){
                addEdge(i, x+M, 1);
            }
        }
        for(int i = 3; i <= n; i++) addEdge(i+M, i, 1);
        addEdge(0, 1, k);
        
        printf("Case %d:\n", tc);
        if(flow() < k) printf("Impossible\n");
        else{
            p[0] = 0;
            build(0);
            assert(ans.size() == k);
            forn(i, ans.size()){
                for(int x : ans[i]) printf("%d ", x);
                printf("2\n");
            }
        }
        printf("\n");
    }



    return 0;
}
