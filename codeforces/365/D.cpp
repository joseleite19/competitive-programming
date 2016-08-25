#include <bits/stdc++.h>

#define oo 100000000
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define MAXN 1000006

using namespace std;

class SegTree{
	vector<int> st;
	int n;

	int query(int p, int L, int R, int i, int j){
		if(j < L || i > R) return 0;
		if(L >= i && R <= j) return st[p];
		int mid = (L+R)/2;
		return query(2*p, L, mid, i, j)^query(2*p+1, mid+1, R, i, j);
	}

	void update(int p, int L, int R, int i, int v){
		if(L == i && i == R){
			st[p] ^= v;
			return;
		}
		if(i < L || R < i) return;
		int mid = (L+R)/2;
		if(i <= mid) update(2*p, L, mid, i, v);
		else update(2*p+1, mid+1, R, i, v);
		st[p] = st[2*p] ^ st[2*p+1];
	}

public:

	SegTree(int size){
		n = size;
		st.assign(4*(n+10), 0);
	}

	int query(int i, int j){
		return query(1, 0, n-1, i, j);
	}

	void update(int i, int v){
		update(1, 0, n-1, i, v);
	}
};

int main(){
	int n, v[MAXN], ans[MAXN];

	scanf("%d", &n);

	SegTree st(n);


	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
		st.update(i, v[i]);
	}

	int m, a, b;

	vector<pair<int, int> > query[MAXN];

	scanf("%d", &m);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b); a--; b--;
		query[b].pb(mp(a, i));
	}

	map<int, int> last;
	for(int i = 0; i < n; i++){
		if(last.find(v[i]) != last.end())
			st.update(last[ v[i] ], v[i]);
		last[ v[i] ] = i;
		st.update(last[ v[i] ], v[i]);

		for(int j = 0; j < query[i].size(); j++){
			pair<int, int> tmp = query[i][j];
			ans[tmp.ss] = st.query(tmp.ff, i);
		}
	}

	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	return 0;
}