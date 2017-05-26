#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);
}

long long ft[1000006];

void update(long long x, long long v){
	for(; x < 1000006; x += x&-x)
		ft[x] += v;
}

long long query(long long x){
	long long ans = 0;
	for(; x; x -= x&-x)
		ans += ft[x];
	return ans;
}

long long n;
pair<long long, long long> cf[1000006], tc[1000006];
long long ans[1000006];

vector<int> g[100005];
vector<int> gt[100005];
vector<int> gc[100005];

int fim[400005];
int sz[400005];

int color[400005];
int t = 1;

int vis[200005], pass;
void dfs_tmp(int u){
	vis[u] = pass;
	for(int v : g[u])
		if(vis[v] != pass)
			dfs_tmp(v);

	fim[u] = t++;
}

void dfst(int u, int c){
	color[u] = c;
	sz[ color[u] ]++;
	vis[u] = pass;
	for(int v : gt[u])
		if(vis[v] != pass)
			dfst(v, c);
}
void build(int u){
	vis[u] = pass;
	for(int v : g[u]){
		if(color[v] != color[u])
			gc[ color[u] ].push_back(color[v]);

		if(vis[v] != pass)
			build(v);
	}

}

int dfs(int u){
	vis[u] = pass;
	for(int v : gc[u]){
		if(vis[v] != pass)
			sz[u] += dfs(v);
	}

	return sz[u];
}

int main(){
	// file();

	scanf("%lld", &n);

	for(long long i = 0; i < n; i++){
		scanf("%lld %lld", &cf[i].ff, &tc[i].ff);
		cf[i].ss = tc[i].ss = i;
	}

	sort(cf, cf+n);
	sort(tc, tc+n);

	for(int i = 0; i+1 < n; i++){
		g[ cf[i+1].ss ].push_back( cf[i].ss );
		g[ tc[i+1].ss ].push_back( tc[i].ss );
		
		gt[ cf[i].ss ].push_back( cf[i+1].ss );
		gt[ tc[i].ss ].push_back( tc[i+1].ss );

	}

	pass++;
	for(int i = 0; i < n; i++)
		if(vis[i] != pass)
			dfs_tmp(i);


	int e = 0;
	{
		vector<pair<int, int> > tmp;
		for(int i = 0; i < n; i++)
			tmp.emplace_back(fim[i], i);
		sort(tmp.begin(), tmp.end(), greater<pair<int, int> >() );

		pass++;

		for(int i = 0; i < int(tmp.size()); i++){
			if(vis[ tmp[i].second ] == pass) continue;
			dfst(tmp[i].second, e++);
		}
	}

	pass++;

	for(int i = 0; i < n; i++)
		if(vis[i] != pass)
			build(i);

	pass++;

	for(int i = 0; i < e; i++){
		if(vis[i] != pass)
			dfs(i);
	}

	for(int i = 0; i < n; i++)
		ans[i] = sz[ color[i] ]-1;



	for(long long i = 0; i < n; i++)
		printf("%lld\n", ans[i]);

	return 0;
}