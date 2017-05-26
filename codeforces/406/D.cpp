#include <bits/stdc++.h>

#define oo (100000000000000000)

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int limit = 1000006;

vector<pair<int, long long> > g[limit]; // vx, cost

long long dist[limit];

class Segtree{
	vector<int> st;
	int n;

	vector<int> ans;

	void get(int p, int L, int R, int i, int j){
		if(j < L || i > R) return;
		if(i <= L && R <= j){
			// CONSIDERA
			ans.push_back(n+p);
			return;
		}
		int mid = (L+R)/2;
		get(2*p, L, mid, i, j);
		get(2*p+1, mid+1, R, i, j);
	}

	void init(int p, int L, int R){
		if(L == R){
			g[L].push_back(mp(6*n+p,0));
			g[n+p].push_back(mp(L,0));
			return;
		}
		int mid = (L+R)/2;
		init(2*p, L, mid);
		init(2*p+1, mid+1, R);

		for(int i = L; i <= R; i++){
			g[n+p].push_back(mp(i, 0));
			g[i].push_back(mp(6*n+p, 0));
		}
	}

public:
	Segtree(int size = 0) : n(size), st(4*(size+5), 0){
		init(1, 1, n);
	}

	vector<int> get(int i, int j){
		ans.clear();
		get(1, 1, n, i, j);
		return ans;
	}
};

void dijsktra(int s){

	for(int i = 0; i < limit; i++)
		dist[i] = oo;

	priority_queue<pair<long long, int> > q;
	dist[s] = 0;
	q.push(mp(0LL, s));

	while(!q.empty()){
		long long d = -q.top().ff;
		int u = q.top().ss; q.pop();

		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].ff;
			long long w = d + g[u][i].ss;

			if(dist[v] > w){
				dist[v] = w;
				q.push(mp(-w, v));
			}
		}
	}
}

int main(){
	int n, q, s;

	scanf("%d %d %d", &n, &q, &s);

	Segtree st(n);

	int t, u, v, l, r;
	long long w;
	for(int i = 0; i < q; i++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d %lld", &u, &v, &w);
			g[u].push_back(mp(v, w));
		}
		else if(t == 2){
			scanf("%d %d %d %lld", &v, &l, &r, &w);
			vector<int> tmp = st.get(l, r);
			for(int j = 0; j < (int)tmp.size(); j++){
				g[v].push_back(mp(tmp[j], w));
			}
		}
		else if(t == 3){
			scanf("%d %d %d %lld", &v, &l, &r, &w);
			vector<int> tmp = st.get(l, r);
			for(int j = 0; j < (int)tmp.size(); j++){
				g[tmp[j]+5*n].push_back(mp(v, w));
			}
		}
	}

	dijsktra(s);

	for(int i = 1; i <= n; i++)
		printf("%lld ", dist[i] == oo ? -1 : dist[i]);
	printf("\n");

	return 0;
}